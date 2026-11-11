import re
from typing import Any
from llm_sdk.llm_sdk import Small_LLM_Model as SLM
from .tokenization_files import (token_allowed_generation,
                                 from_prompt_to_token,
                                 get_higher_allowed_token)
from .models import ParameterDefinition


NUMBER_PREFIX = re.compile(r"-?(\d+(\.\d*)?)?")
NUMBER_COMPLETE = re.compile(r"-?\d+(\.\d+)?")
MAX_VALUE_TOKENS = 40


def create_value_mask(id_to_token: dict[int, str]) -> dict[str, set[int]]:
    mask: dict[str, set[int]] = {
        "digits": set(), "comma": set(), "quote": set(), "brace": set(),
        "string": set()
    }
    for token_id, text in id_to_token.items():
        if text and all(c in "0123456789.-" for c in text):
            mask["digits"].add(token_id)
        if '"' in text:
            mask["quote"].add(token_id)
        elif text == ",":
            mask["comma"].add(token_id)
        elif text == "}":
            mask["brace"].add(token_id)
        if text and not any(c in '"\\' or ord(c) < 32 for c in text):
            mask["string"].add(token_id)
    return mask


def create_number(modello: SLM,
                  token_prompt: list[int],
                  id_to_token: dict[int, str],
                  digits: set[int],
                  end_ids: set[int]) -> float:
    text: str = ""
    for _ in range(MAX_VALUE_TOKENS):
        allowed = {i for i in digits if NUMBER_PREFIX.fullmatch(text +
                                                                id_to_token[i]
                                                                )}
        if NUMBER_COMPLETE.fullmatch(text):
            allowed |= end_ids
        logits = modello.get_logits_from_input_ids(token_prompt)
        token = get_higher_allowed_token(logits, allowed)
        if token in end_ids:
            return float(text)
        token_prompt.append(token)
        text += id_to_token[token]
    raise ValueError("No number")


def create_string(modello: SLM, token_prompt: list[int], allowed: set[int],
                  quote_id: set[int], id_to_token: dict[int, str]) -> Any:
    ids: list[int] = []
    for _ in range(MAX_VALUE_TOKENS * 3):
        logits = modello.get_logits_from_input_ids(token_prompt)
        token = get_higher_allowed_token(logits, allowed | quote_id)
        if token in quote_id:
            before_quote = search_before_quote(id_to_token[token])
            if before_quote:
                complete = from_prompt_to_token(before_quote, modello)
                token_prompt.extend(complete)
                ids.extend(complete)
            break
        else:
            token_prompt.append(token)
            ids.append(token)
    return modello.decode(ids)


def create_parameters(modello: SLM, token_prompt: list[int],
                      params: dict[str, ParameterDefinition],
                      id_to_token: dict[int, str],
                      mask: dict[str, set[int]]) -> dict[str, Any]:
    values: dict[str, Any] = {}
    names = list(params)
    for i, name in enumerate(names):
        the_type = params[name].type
        if i == 0:
            start = '", "parameters": {'
        else:
            start = ', '
        if the_type == "string":
            opening = '"'
        else:
            opening = ""
        static_part = f'{start}"{name}": {opening}'
        token_prompt.extend(from_prompt_to_token(static_part, modello))
        if the_type == "number":
            last = i == len(names) - 1
            if last:
                end_ids = mask["brace"]
            else:
                end_ids = mask["comma"]
            values[name] = create_number(modello, token_prompt, id_to_token,
                                         mask["digits"], end_ids)
        elif the_type == "string":
            values[name] = create_string(modello, token_prompt,
                                         mask["string"], mask["quote"],
                                         id_to_token)
            token_prompt.extend(from_prompt_to_token('"', modello))
        elif the_type == "boolean":
            text = token_allowed_generation(["true", "false"], modello,
                                            token_prompt, id_to_token)
            values[name] = text == "true"
        else:
            raise ValueError("wrong types")
    return values


def search_before_quote(token: str) -> str:
    for i, char in enumerate(token):
        if char == '"':
            return token[:i]
    return token

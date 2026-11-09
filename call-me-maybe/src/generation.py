import re
from typing import Any
from llm_sdk.llm_sdk import Small_LLM_Model as SLM
from .tokenization_files import (token_allowed_generation,
                                 from_prompt_to_token,
                                 get_higher_allowed_token)
from .models import ParameterDefinition
import numpy as np


NUMBER_PREFIX = re.compile(r"-?(\d+(\.\d*)?)?")
NUMBER_COMPLETE = re.compile(r"-?\d+(\.\d+)?")
# STRING_PREFIX = re.compile(r"?(\d+(\.\d*)?)?")

MAX_VALUE_TOKENS = 40


def create_value_mask(id_to_token: dict[int, str]) -> dict[str, set[int]]:
    mask: dict[str, set[int]] = {
        "digits": set(), "comma": set(), "quote": set(), "brace": set(),
        "string": set()
    }
    for token_id, text in id_to_token.items():
        if text and all(c in "0123456789.-" for c in text):
            mask["digits"].add(token_id)
        if text == '"':
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
                  quote_id: set[int], a) -> str:
    ids: list[int] = []
    print(a)
    for _ in range(MAX_VALUE_TOKENS * 3):
        logits = modello.get_logits_from_input_ids(token_prompt)
        token = get_higher_allowed_token(logits, allowed | quote_id)
        # print(repr(modello.decode([int(np.argmax(logits))])), repr(modello.decode([token])))
        if token in quote_id:
            break
        token_prompt.append(token)
        ids.append(token)
        print(modello.decode([token]), sep="", end="", flush=True)
    print()
    print(np.argmax(token_prompt))
    return modello.decode(ids)


def create_parameters(modello: SLM, token_prompt: list[int],
                      params: dict[str, ParameterDefinition],
                      id_to_token: dict[int, str],
                      mask: dict[str, set[int]]) -> dict[str, Any]:
    values: dict[str, Any] = {}
    names = list(params)
    a:  int = 0
    for i, name in enumerate(names):
        the_type = params[name].type
        if i == 0:
            start = '", "parameters": {'
        else:
            start = ', '
        if the_type == "string":
            opening = "'"
        else:
            opening = ""
        static_part = f'{start}"{name}": {opening}'
        token_prompt.extend(from_prompt_to_token(static_part, modello))
        if the_type == "number":
            print("sono passato di qui 1")
            last = i == len(names) - 1
            if last:
                end_ids = mask["brace"]
            else:
                end_ids = mask["comma"]
            values[name] = create_number(modello, token_prompt, id_to_token,
                                         mask["digits"], end_ids)
        elif the_type == "string":
            print(np.argmax(token_prompt))
            print(f"sono tornato dentro string {a} volte")
            # print([t for t in id_to_token.values() if t.startswith('"')][:30])
            # print(token_prompt)
            values[name] = create_string(modello, token_prompt,
                                         mask["string"], mask["quote"], a)
            token_prompt.extend(from_prompt_to_token('"', modello))
            a += 1
            print("ciao", token_prompt)
        elif the_type == "boolean":
            print("sono passato di qui 2")
            text = token_allowed_generation(["true", "false"], modello,
                                            token_prompt, id_to_token)
            if text == "true":
                values[name] = text
        else:
            raise ValueError()
    return values

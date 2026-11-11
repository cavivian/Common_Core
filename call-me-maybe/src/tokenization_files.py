# from .models import CheckPrompt
from llm_sdk.llm_sdk import Small_LLM_Model as SLM
import json
import numpy as np
from typing import Any


def build_prompt(functions_text: str, user_prompt: str) -> str:
    """Build the chat-formatted text that Qwen3 expects.

    Args:
        functions_text: JSON text describing the available functions.
        user_prompt: The natural-language request of the user.

    Returns:
        The full conversation, ending where the assistant must answer.
    """
    return (
        "<|im_start|>system\n"
        f"{functions_text}<|im_end|>\n"
        "<|im_start|>user\n"
        f"{user_prompt}<|im_end|>\n"
        "<|im_start|>assistant\n"
        "<think>\n\n</think>\n\n"
    )


def from_prompt_to_token(prompt: str, modello: SLM) -> Any:
    request = modello.encode(prompt)[0].tolist()
    return request


def token_id_allowed(generated: str,
                     names: list[str],
                     id_to_token: dict[int, str]
                     ) -> set[int]:
    allowed = set()
    for id_token, text in id_to_token.items():
        if any(n.startswith(generated + text) for n in names):
            allowed.add(id_token)
    return allowed


def load_vocab(modello: SLM) -> dict[int, str]:
    path = modello.get_path_to_vocab_file()
    with open(path, encoding="utf-8") as f:
        d = json.load(f)
    inverso = {v: k.replace("Ġ", " ").replace("Ċ", "\n") for k, v in d.items()}
    return inverso


def token_allowed_generation(choices: list[str], modello: SLM,
                             token_prompt: list[int],
                             id_to_token: dict[int, str],
                             ) -> str:
    generated = ""
    while generated not in choices:
        allowed = token_id_allowed(generated, choices, id_to_token)
        logits = modello.get_logits_from_input_ids(token_prompt)
        token = get_higher_allowed_token(logits, allowed)
        token_prompt.append(token)
        generated += id_to_token[token]
    return generated


def get_higher_allowed_token(logits: list[float], allowed: set[int]) -> int:
    if not allowed:
        raise ValueError(f"nessun token valido dopo {allowed!r}")
    scores = np.full(len(logits), -np.inf)
    ids = np.fromiter(allowed, dtype=int)
    scores[ids] = np.asarray(logits)[ids]
    return int(np.argmax(scores))

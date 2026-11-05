# from .models import CheckPrompt
from llm_sdk.llm_sdk import Small_LLM_Model as SLM
import json
import numpy as np


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


def from_prompt_to_token(prompt: str, modello: SLM) -> list[int]:
    request = modello.encode(prompt)[0].tolist()
    return request


# questa funzione che mi controlla se effettivamente
# c'e' nel json cio' che cerco
def token_id_allowed(generated: str,
                     names: list[str],
                     id_to_token: dict[int, str]
                     ) -> set[int]:
    allowed = set()
    for id_token, text in id_to_token.items():
        if any(n.startswith(generated + text) for n in names):
            allowed.add(id_token)
            # print()
            # print(allowed, end="")
            # print()
    return (allowed)


def load_vocab(modello: SLM) -> dict[int, str]:
    path = modello.get_path_to_vocab_file()
    with open(path, encoding="utf-8") as f:
        d = json.load(f)
    inverso = {v: k.replace("Ġ", " ").replace("Ċ", "\n") for k, v in d.items()}
    return inverso
    # print(inverso)


def token_allowed_generation(generated: str, names: list[str], modello: SLM,
                             token_prompt: list[int],
                             id_to_token: dict[int, str],
                             test) -> str:
    while generated not in names:  # finchè non è uno dei nomi
        logits = modello.get_logits_from_input_ids(token_prompt)
        # ^ mi calcola il logit dei token
        allowed = token_id_allowed(generated, names, id_to_token)
        # ^ check se un logit è ammesso o no
        if not allowed:
            raise ValueError(f"nessun token valido dopo {generated!r}")
        for i in range(len(logits)):  # mi scorre tutti i logit creati
            if i not in allowed:  # se non e' tra quelli validi
                logits[i] = float("-inf")  # lo setta a -inf,
                # per rendere impossibile il suo pescaggio
        next_token = int(np.argmax(logits))  # token con il più alto logit
        token_prompt.append(next_token)  # qua gli aggiungo i token del nome
        generated += id_to_token[next_token]
        dec = modello.decode(next_token)
        print(dec)
        print(test.prompt, "->", generated)
    return generated

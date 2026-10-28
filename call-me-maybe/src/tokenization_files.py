# from .models import CheckPrompt
from llm_sdk.llm_sdk import Small_LLM_Model as SLM
import json


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


def from_text_to_token(prompt: str, modello: SLM) -> list[int]:
    request = modello.encode(prompt)[0].tolist()
    return request


def token_id_allowed(generated: str, names: list[str], id_to_token: dict[int, str]) -> set[int]:
    for item in id_to_token.items():
        pass
    # return word
    # print(word)
    # print(" sono dentro 'token_id_allowed'", generated)


def load_vocab(modello: SLM) -> dict[int, str]:
    d = modello.get_path_to_vocab_file()
    with open(d) as f:
        path = json.load(f)
    inverso = {v: k for k, v in path.items()}
    return inverso
    # print(inverso)

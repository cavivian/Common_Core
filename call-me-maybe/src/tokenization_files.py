from .models import CheckPrompt


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


def go_to_model(prompt: list[CheckPrompt], modello) -> list[int]:
    token: list[int] = []
    
    for request in prompt:
        request = modello.encode()
        token.append(request)
    return token

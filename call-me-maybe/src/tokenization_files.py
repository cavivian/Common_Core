from .models import CheckPrompt


def prompt_tokenization(prompt: list[CheckPrompt]) -> list[int]:
    token: list[int] = []
    for request in prompt:
        request = request.encode()
        token.append(request)
    return token

from llm_sdk import Small_LLM_Model as SLM
import numpy as np

# quello che devo fare io e':
# passare functions_definition.json a system
# passare functions_call.json a user
# ricreare format (e' vietato dal subject)
# ricreare get_logits_from_input_ids
# ricreare tokenizer
# ricreare eos_token_id
# e le altre cose che chiederò a Claude


def main() -> None:
    model = SLM()
    richiesta = [
        {"role": "system", "content": "rispondi brevemente solo con il risultato."},
        {"role": "user", "content": "quante zampe ha un cavallo?"}
        ]
    print("end_of_sentence:", model._tokenizer.eos_token_id)
    formatted = model.format(richiesta)
    encoding = model.encode(formatted)[0].tolist()
    # print(encoding)
    encoding_risposta = []
    risposta = ""
    for _ in range(50):
        logits = model.get_logits_from_input_ids(encoding)
        next_token = np.argmax(logits)
        next_word = model.decode([next_token])
        print(next_word, end="", flush=True)
        if next_token == model._tokenizer.eos_token_id:
            break
        encoding.append(next_token)
        encoding_risposta.append(next_token)
        risposta += next_word
    print()


if __name__ == "__main__":
    main()

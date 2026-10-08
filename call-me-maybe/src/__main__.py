from llm_sdk import Small_LLM_Model as SLM
import numpy as np
from .parse import argument_parser
from pydantic import BaseModel
from typing import Union
import json
from .files_handle import load_json_file

# quello che devo fare io e':
# passare functions_definition.json a system
# passare functions_call.json a user
# ricreare le funzioni che hanno _ davanti al nome
# ricreare la mappa token_id -> stringa del token dal vocab file
# lettura dei due json e gestione degli errori
# logica di validazione incrementale del json (sono dentro {}? sto scrivendo
# un chiave? un valore stringa, un numero?)
# vincolo che il valore "name" sia uno dei nomi di funzione noti
# vincolo sui tipi di parametri
# sostituzione di np.argmax(logits) con "argmax solo tra i token ammessi"
# criterio di stop basato sulla struttura completa, non su eos_token_id
# agparse per --functions_definition, --input e --output con path di default


typeofparameter = Union[str, float, bool, dict, list]


class ParameterDefinition(BaseModel):
    type: typeofparameter


class CheckPrompt(BaseModel):
    prompt: str


class CheckFunctionsDefinition(BaseModel):
    name: str
    description: str
    parameters: dict[str, ParameterDefinition]
    returns: ParameterDefinition


def main() -> None:
    args = argument_parser()
    if not args:
        return None
    modello = SLM()
    loaded_data = load_json_file("data/input/functions_definition.json",
                                 CheckFunctionsDefinition)
    tests = load_json_file("data/input/function_calling_tests.json",
                           CheckPrompt)
    # Fuori dal ciclo: serializzo le funzioni una volta sola
    functions_text = json.dumps([f.model_dump() for f in loaded_data])
    print(functions_text)
    for test in tests:
        richiesta = [
            {"role": "system", "content": functions_text},
            {"role": "user", "content": test.prompt}
        ]
        # a questo result devo aggiungere anche la description
    result = CheckFunctionsDefinition(name=test.name, prompt=test.prompt,
                                      parameters=test.params)
    results = list[result]
    print(results)
    # qui dentro: genera la function call per QUESTO prompt
    # e accumula il risultato da qualche parte (es. una lista `results`)
    print("end_of_sentence:", modello._tokenizer.eos_token_id)
    formatted = modello.format(richiesta)
    encoding = modello.encode(formatted)[0].tolist()
    # print(encoding)
    encoding_risposta = []
    risposta = ""
    for _ in range(50):
        logits = modello.get_logits_from_input_ids(encoding)
        next_token = np.argmax(logits)
        next_word = modello.decode([next_token])
        print(next_word, end="", flush=True)
        if next_token == modello._tokenizer.eos_token_id:
            break
        encoding.append(next_token)
        encoding_risposta.append(next_token)
        risposta += next_word
        print()


if __name__ == "__main__":
    main()

from llm_sdk import Small_LLM_Model as SLM
import numpy as np
import agparse
from pydantic import BaseModel, ValidationError, TypeAdapter
from typing import Literal
import json

# quello che devo fare io e':
# passare functions_definition.json a system
# passare functions_call.json a user
# ricreare le funzioni che hanno _ davanti al nome
# ricreare la mappa token_id -> stringa del token dal vocab file
# lettura dei due json e gestione degli errori
# logica di validazione incrementale del json (sono dentro {}? sto scrivendo un chiave? un valore stringa, un numero?)
# vincolo che il valore "name" sia uno dei nomi di funzione noti
# vincolo sui tipi di parametri
# sostituzione di np.argmax(logits) con "argmax solo tra i token ammessi"
# criterio di stop basato sulla struttura completa, non su eos_token_id
# agparse per --functions_definition, --input e --output con path di default
# 

typeofparameter = Literal["string", "number", "boolean", "array", "object"]


class ParameterDefinition(BaseModel):
    type: typeofparameter


class InputFileError(Exception):
    pass


class CheckPrompt(BaseModel):
    prompt: str


class CheckFunctionsDefinition(BaseModel):
    name: str
    description: str
    parameters: dict[str, ParameterDefinition]
    returns: ParameterDefinition


def load_json_file(path: str, model: type[BaseModel]) -> list[BaseModel]:
    try:
        with open(path, "r", encoding="utf-8") as f:
            data = json.load(f)
    except FileNotFoundError as e:
        print(f"File not found: {e}")
        raise InputFileError("Input file not found")
    except json.JSONDecodeError as e:
        print(f"Error decoding JSON: {e}")
        raise InputFileError("Invalid JSON format")
    try:
        return (TypeAdapter(model).validate_python(data))
    except ValidationError as e:
        print(f"Validation error: {e}")
        raise InputFileError("Validation error in JSON data")


def main() -> None:
    try:
        loaded_data = load_json_file("data/input/functions_definition.json",
                                     CheckFunctionsDefinition)
        tests = load_json_file("data/input/function_calling_tests.json",
                               CheckPrompt)
    except InputFileError as e:
        print(e)
        raise SystemExit("Exiting due to input file error.")
    modello = SLM()
    richiesta = [
        {"role": "system", "content": "rispondi brevemente solo con il"
         " risultato."},
        {"role": "user", "content": loaded_data}
        ]
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

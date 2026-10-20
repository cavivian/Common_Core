from llm_sdk.llm_sdk import Small_LLM_Model as SLM
import numpy as np
from .parse import argument_parser
from pydantic import BaseModel
from typing import Literal
import json
from .files_handle import load_json_file, InputFileError, write_output_file, OutputFileError
from pathlib import Path

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


typeofparameter = Literal["string", "number", "boolean", "array", "object"]


# descrive che tipo è un parametro
class ParameterDefinition(BaseModel):
    type: typeofparameter


class CheckPrompt(BaseModel):
    prompt: str


# mi controlla i parametri in uscita da inserire del messaggio di output
# ottengo un dizionario
class CheckOutputParameters(BaseModel):
    name: str
    prompt: str
    parameters: dict[str, ParameterDefinition]


class CheckFunctionsDefinition(BaseModel):
    name: str
    parameters: dict[str, ParameterDefinition]
    description: str
    returns: ParameterDefinition


def main() -> None:
    args = argument_parser()
    try:
        loaded_data = load_json_file(args.functions_definition,
                                     CheckFunctionsDefinition)
        tests = load_json_file(args.input,
                               CheckPrompt)
    except InputFileError as e:
        raise SystemExit(e)
    modello = SLM(args.model_name)
    # Fuori dal ciclo: serializzo le funzioni una volta sola
    # mi restituisce una stringa
    functions_text = json.dumps([f.model_dump() for f in loaded_data])
    # print(functions_text)
    results = []
    # tutto ciò che è dentro questo ciclo va tokenizzato e passato al modello, così non basta
    # prima va tokenizzato il prompt e passato al modello, dopo gli va dato il contesto con
    # l'altro json, anche quello a sua volta tokenizzato
    # una volta ottenuti entrambi si genera la risposta, si decoda
    # si restituisce in un file json
    # sia test che function sono oggetti pydantic perchè dentro funzioni con BaseModel
    for test in tests:
        for function in loaded_data:
            # print(test)
            richiesta = [
                {"role": "system", "content": functions_text},
                {"role": "user", "content": test.prompt}
            ]
            result = CheckOutputParameters(prompt=test.prompt, name=function.name,
                                           parameters=function.parameters)
            # questo è ciò che devo inserire nel file di output json
            results.append(result) 
            # se lo passo a json.dump() restituisce TypeError perchè è una lista di oggetti pydantic, ma non di dict
    print(results)
    # qui dentro: genera la function call per QUESTO prompt
    # e accumula il risultato da qualche parte (es. una lista `results`)
    # print("end_of_sentence:", modello._tokenizer.eos_token_id)
    # print(encoding)
    encoding_answer = []
    answer = ""
    for _ in results:  # qua anziche' range, va passata la lista di prompt,
        # la mia results
        formatted = modello.format(richiesta)
        encoding = modello.encode(formatted)[0].tolist()
        logits = modello.get_logits_from_input_ids(encoding)
        next_token = np.argmax(logits)
        next_word = modello.decode([next_token])
        # print(next_word, end="", flush=True)
        # io qua non devo printare niente,
        # il risultato deve essere dentro un file json
        if next_token == modello._tokenizer.eos_token_id:
            break
        encoding.append(next_token)
        encoding_answer.append(next_token)
        answer += next_word
        # print()
        # qua va aperto il file di output, e passata la risposta e
        # validata in tipo json usando le funzioni:
        # json.dumps(-per le stringhe) o json.dump(-per scrivere il file json)
    try:
        path = args.output
        write_output_file(results, path)
    except OutputFileError as e:
        raise SystemExit(e)
    


if __name__ == "__main__":
    main()

from llm_sdk.llm_sdk import Small_LLM_Model as SLM
# /import numpy as np
from .parse import argument_parser
import json
from .files_handle import (load_json_file, InputFileError, write_output_file,
                           OutputFileError)
from .tokenization_files import build_prompt, from_text_to_token
from .models import (CheckFunctionsDefinition,
                     CheckOutputParameters,
                     CheckPrompt)


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


def main() -> None:
    args = argument_parser()
    try:
        loaded_data = load_json_file(args.functions_definition,
                                     CheckFunctionsDefinition)
        tests = load_json_file(args.input,
                               CheckPrompt)
    except InputFileError as e:
        raise SystemExit(e)
    try:
        modello = SLM(args.model_name)
        functions_text = json.dumps([f.model_dump() for f in loaded_data])
        print(functions_text)
        print()
        results = []
        for test in tests:
            for function in loaded_data:
                formatted = build_prompt(functions_text, test.prompt)
                result = CheckOutputParameters(prompt=test.prompt,
                                               name=function.name,
                                               parameters=function.parameters)
                datas_validate = result.model_dump()
                results.append(datas_validate)
                token_prompt = from_text_to_token(formatted, modello)
        print(formatted)
        print()
        print(token_prompt)
        word = modello.decode(token_prompt)
        print()
        print(word)
        # print(results)
    except PermissionError as e:
        raise SystemExit(e)
    try:
        path = args.output
        write_output_file(results, path)
    except OutputFileError as e:
        raise SystemExit(e)


if __name__ == "__main__":
    main()

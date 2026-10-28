from llm_sdk.llm_sdk import Small_LLM_Model as SLM
import numpy as np
from .parse import argument_parser
import json
from .files_handle import (load_json_file, InputFileError, write_output_file,
                           OutputFileError
                           )
from .tokenization_files import (build_prompt,
                                 from_text_to_token,
                                 token_id_allowed,
                                 load_vocab
                                 )
from .models import (CheckFunctionsDefinition,
                     CheckOutputParameters,
                     CheckPrompt
                     )


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
# argparse per --functions_definition, --input e --output con path di default


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
        dizionario = {}
        names = [f.name for f in loaded_data]
        id_to_token = load_vocab(modello)
        print(len(id_to_token))
        print(id_to_token[0], id_to_token[1], id_to_token[2])
        print([t for t in id_to_token.values() if t.startswith("fn")][:10])
        for test in tests:
            formatted = build_prompt(functions_text, test.prompt)
            generated: str = ""
            print("sto per entrare nel ciclo, sono prima del while")
            token_prompt = from_text_to_token(formatted, modello)
            while generated not in names:  # qui devo fare la funzione che mi controlli i nomi delle funzioni
                # print("sono dentro il ciclo")
                logits = modello.get_logits_from_input_ids(token_prompt)
                allowed = token_id_allowed(generated, names, id_to_token)
                for i in range(len(logits)):
                    if i not in allowed:
                        logits[i] = float("-inf")
                token_id_allowed(generated, modello)
                next_token = int(np.argmax(logits))
                token_prompt.append(next_token)
                generated += id_to_token[next_token]
            # v- cio' che deve essere ritornato dentro il json
            print("sono appena uscito dal ciclo")
            result = CheckOutputParameters(name=generated,
                                           prompt=test.prompt,
                                           parameters=dizionario
                                           )
            datas_validate = result.model_dump()
            results.append(datas_validate)
        print("\n sono passata di qui \n", generated)
        print()
        print(results)
        print()
        # print(len(logits))
        print()
        # print(next_token)
        print()
        # print(next_word)
        print()
        print(formatted)
        print()
        print(result)
        print()
        # print(token_prompt)
        # word = modello.decode(token_prompt)
        print()
        # print(word)
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

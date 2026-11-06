from llm_sdk.llm_sdk import Small_LLM_Model as SLM
from .parse import argument_parser
import json
from .files_handle import (load_json_file, InputFileError, write_output_file,
                           OutputFileError
                           )
from .tokenization_files import (build_prompt,
                                 from_prompt_to_token,
                                 load_vocab,
                                 token_allowed_generation
                                 )
from .models import (CheckFunctionsDefinition,
                     CheckOutputParameters,
                     CheckPrompt
                     )
from .generation import create_value_mask, create_parameters


# quello che devo fare io e':
# ricreare la mappa token_id -> stringa del token dal vocab file
# logica di validazione incrementale del json (sono dentro {}? sto scrivendo
# un chiave? un valore stringa, un numero?)
# vincolo sui tipi di parametri
# criterio di stop basato sulla struttura completa, non su eos_token_id


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
        results = []  # ciò che va passato all'output
        # dizionario = {}
        names = [f.name for f in loaded_data]  # sono i nomi delle funzioni,
        # quelli che iniziano per fn_
        id_to_token = load_vocab(modello)
        # ^ caricamento del vocabolario dei token
        print(len(id_to_token))
        print(id_to_token[0], id_to_token[1], id_to_token[2])
        print([t for t in id_to_token.values() if t.startswith("fn")][:10])
        # v tutto questo ciclo e' solo per cercare il nome del prompt
        # e verificare che ci sia, e per trovare i parametri
        # corrispondenti a quella funzione
        mask = create_value_mask(id_to_token)
        for test in tests:  # ciclo che scorre i prompt
            formatted = build_prompt(functions_text, test.prompt)
            token_prompt = from_prompt_to_token(formatted, modello)
            token_prompt.extend(from_prompt_to_token('{"name": "',
                                                     modello))
            generated = token_allowed_generation(names, modello, token_prompt,
                                                 id_to_token)
            params = next(f.parameters for f in loaded_data
                          if f.name == generated)
            values = create_parameters(modello, token_prompt, params,
                                       id_to_token, mask)
            result = CheckOutputParameters(name=generated,
                                           prompt=test.prompt,
                                           parameters=values
                                           )
            results.append(result.model_dump())
            print()
            print("sto per entrare nel ciclo, sono prima del while")
            # ^ lista che contiene tutti i token del prompt
            # generated = token_allowed_generation(generated, names, modello,
            #                                      token_prompt,
            #                                      id_to_token,
            #                                      test)
            # prende i parametri da definizione della funzione loaded_dat
            print()
            print("sono appena uscito dal ciclo")
            # v- cio' che deve essere ritornato dentro il json
        print("\n sono passata di qui \n", generated)
        print()
        print()
        print(results)
        # print()
        # print(len(logits))
        # print()
        # print(next_token)
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

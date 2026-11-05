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


# quello che devo fare io e':
# ricreare la mappa token_id -> stringa del token dal vocab file
# logica di validazione incrementale del json (sono dentro {}? sto scrivendo
# un chiave? un valore stringa, un numero?)
# vincolo sui tipi di parametri
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
        for test in tests:  # ciclo che scorre i prompt
            formatted = build_prompt(functions_text, test.prompt)
            # si costruisce la formattazione del prompt secondo il modello
            generated: str = ""  # stringa che contiene i nomi generati
            print()
            print("sto per entrare nel ciclo, sono prima del while")
            token_prompt = from_prompt_to_token(formatted, modello)
            # ^ lista che contiene tutti i token del prompt
            generated = token_allowed_generation(generated, names, modello,
                                                 token_prompt,
                                                 id_to_token,
                                                 test)
            parameter_store = {}
            if generated in names:
                params = next(f.parameters for f in loaded_data
                              if f.name == generated)
                # prende i parametri da definizione della funzione loaded_data
                for i, param_name in enumerate(params):
                    last = (i == len(params) - 1)   # True solo per l'ultimo
                    terminator = "}" if last else ","
                    if i == 0:
                        # Usiamo gli apici singoli per delimitare la f-string
                        testo = f'", "parameters": {{"{param_name}": '
                    else:
                        testo = f'"{param_name}": '
                token_prompt.extend(from_prompt_to_token(testo, modello))
                print(i, param_name, last)
            print()
            print("sono appena uscito dal ciclo")
            # v- cio' che deve essere ritornato dentro il json
            result = CheckOutputParameters(name=generated,
                                           prompt=test.prompt,
                                           parameters=params
                                           #  ^ questo va modificato,
                                           # per adesso gli
                                           # passo un dizionario vuoto
                                           # ma devo ancora prendere
                                           # i parametri giusti
                                           )
            results.append(result.model_dump())
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

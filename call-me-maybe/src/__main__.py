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
    i: int = 0
    try:
        modello = SLM(args.model_name)
        functions_text = json.dumps([f.model_dump() for f in loaded_data])
        print(functions_text)
        print()
        results = []
        names = [f.name for f in loaded_data]
        print(names)
        id_to_token = load_vocab(modello)
        print(len(id_to_token))
        print(id_to_token[0], id_to_token[1], id_to_token[2])
        print([t for t in id_to_token.values() if t.startswith("fn")][:10])
        mask = create_value_mask(id_to_token)
        print("sto per entrare nel ciclo, sono prima del while")
        for test in tests:
            print(f"sono entrato nel ciclo {i}")
            formatted = build_prompt(functions_text, test.prompt)
            print("sono dopo formatted")
            token_prompt = from_prompt_to_token(formatted, modello)
            print("sono dopo token prompt")
            token_prompt.extend(from_prompt_to_token('{"name": "',
                                                     modello))
            generated = token_allowed_generation(names, modello, token_prompt,
                                                 id_to_token)
            print("sono dopo generated")
            params = next(f.parameters for f in loaded_data
                          if f.name == generated)
            print("sono dopo params")
            parameters = create_parameters(modello, token_prompt, params,
                                           id_to_token, mask)
            result = CheckOutputParameters(name=generated,
                                           prompt=test.prompt,
                                           parameters=parameters
                                           )
            results.append(result.model_dump())
            print()
            print()
            print("sono appena uscito dal ciclo")
            i += 1
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
        print()
    except PermissionError as e:
        print("sono nel permission error del try del ciclo dei test")
        raise SystemExit(e)
    try:
        path = args.output
        write_output_file(results, path)
    except OutputFileError as e:
        raise SystemExit(e)


if __name__ == "__main__":
    main()

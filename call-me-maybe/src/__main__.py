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
        results = []
        names = [f.name for f in loaded_data]
        id_to_token = load_vocab(modello)
        mask = create_value_mask(id_to_token)
        for test in tests:
            formatted = build_prompt(functions_text, test.prompt)
            token_prompt = from_prompt_to_token(formatted, modello)
            token_prompt.extend(from_prompt_to_token('{"name": "',
                                                     modello))
            generated = token_allowed_generation(names, modello, token_prompt,
                                                 id_to_token)
            params = next(f.parameters for f in loaded_data
                          if f.name == generated)
            parameters = create_parameters(modello, token_prompt, params,
                                           id_to_token, mask)
            result = CheckOutputParameters(name=generated,
                                           prompt=test.prompt,
                                           parameters=parameters
                                           )
            results.append(result.model_dump())
    except (PermissionError, ValueError) as e:
        raise SystemExit(e)
    try:
        path = args.output
        write_output_file(results, path)
    except OutputFileError as e:
        raise SystemExit(e)


if __name__ == "__main__":
    main()

import argparse


def argument_parser() -> argparse.Namespace:
    arguments_parse = argparse.ArgumentParser()
    arguments_parse.add_argument(
        '--function_definition',
        default="data/input/functions_definition.json",
        help="Input path for JSON file"
    )
    arguments_parse.add_argument(
        '--input',
        default="data/input/function_call.json",
        help="Input path for JSON file"
    )
    arguments_parse.add_argument(
        '--output',
        default="data/output/function_calling_results.json",
        help="Output path for JSON file"
    )
    arguments_parse.add_argument(
        '--model_name',
        default="Qwen/Qwen3-0.6B",
        help="Identifier of the model on the HF Hub."
    )
    args = arguments_parse.parse_args()
    return args

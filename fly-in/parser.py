# cosa devo fare:
# - try-except in cui leggo i file dei percorsi
# - fare il parse di tutti i file (sempre dentro il try)
# import argparse
# from typing import Literal


# mode_route = Literal[]

# class Parse:
#     def __init__(self, path):
#         self.path = path

#     def argument_parser() -> argparse.Namespace:
#         arguments_parse = argparse.ArgumentParser()
#         arguments_parse.add_argument(
#             '--easy',
#             default="maps/easy/",
#             help="Input path for JSON file"
#         )
#         arguments_parse.add_argument(
#             '--input',
#             default="data/input/function_calling_tests.json",
#             help="Input path for JSON file"
#         )
#         arguments_parse.add_argument(
#             '--output',
#             default="data/output/function_calling_results.json",
#             help="Output path for JSON file"
#         )
#         arguments_parse.add_argument(
#             '--model_name',
#             default="Qwen/Qwen3-0.6B",
#             help="Identifier of the model on the HF Hub."
#         )
#         args = arguments_parse.parse_args()
#         return args

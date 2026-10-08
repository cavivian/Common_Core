import json
from pydantic import BaseModel, TypeAdapter, ValidationError


class InputFileError(Exception):
    pass


def load_json_file(path: str, model: type[BaseModel]) -> list[BaseModel]:
    try:
        with open(path, "r", encoding="utf-8") as f:
            datas = json.load(f)
    except FileNotFoundError as e:
        print(f"File not found: {e}")
        raise InputFileError("Input file not found")
    except json.JSONDecodeError as e:
        print(f"Error decoding JSON: {e}")
        raise InputFileError("Invalid JSON format")
    try:
        return (TypeAdapter(model).validate_python(datas))
    except ValidationError as e:
        print(f"Validation error: {e}")
        raise InputFileError("Validation error in JSON data")

import json
from typing import TypeVar
from pathlib import Path
from pydantic import BaseModel, ValidationError

T = TypeVar("T", bound=BaseModel)


class InputFileError(Exception):
    """Raised when an input file is missing, unreadable or invalid."""


class OutputFileError(Exception):
    """Raised when an output file is missing, unwriteable or invalid."""


def load_json_file(path: str, model: type[T]) -> list[T]:
    """Read a JSON file containing a list and validate every entry.

    Args:
        path: Path of the JSON file.
        model: Pydantic class used to validate each entry of the list.

    Returns:
        The list of validated entries.

    Raises:
        InputFileError: If the file is missing, unreadable, not valid
            JSON, not a list, or if an entry does not match the model.
    """
    try:
        with open(path, "r", encoding="utf-8") as f:
            data = json.load(f)
    except FileNotFoundError as e:
        raise InputFileError(f"File not found: {path}") from e
    except OSError as e:
        raise InputFileError(f"Cannot read {path}: {e.strerror}") from e
    except UnicodeDecodeError as e:
        raise InputFileError(f"{path} is not valid UTF-8 text") from e
    except json.JSONDecodeError as e:
        raise InputFileError(
            f"Invalid JSON in {path} (line {e.lineno}, column {e.colno}): "
            f"{e.msg}"
        ) from e

    if not isinstance(data, list):
        raise InputFileError(f"{path} must contain a JSON list")

    entries: list[T] = []
    for index, item in enumerate(data):
        try:
            entries.append(model.model_validate(item))
        except ValidationError as e:
            first = e.errors()[0]
            field = ".".join(str(part) for part in first["loc"])
            raise InputFileError(
                f"Invalid entry #{index} in {path}: "
                f"'{field}': {first['msg']}"
            ) from e
    return entries


def write_output_file(answer: list[str], path: str):
    try:
        dir_path = Path(path).parent
        dir_path.mkdir(parents=True, exist_ok=True)
        # parents = crea ogni cartella intermediaria mancata nel percorso
        # exist_ok = previene il FileExistsError se la directory esiste di già
        with open(path, "w", encoding="utf-8") as f:
            json.dump(answer, f, indent=4)
    except OSError as e:
        raise OutputFileError(f"Cannot write {path}: {e.strerror}") from e

write_output_file([{"prompt": "Generate a greeting message for a person by name.", "name": "fn_add_numbers", "parameters": "number, number"},
                   {"prompt": "Add two numbers together and return their sum.", "name": "fn_greet", "parameters": "string"}], "data/output/prova.json")
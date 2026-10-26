from pydantic import BaseModel, Field
from typing import Literal

typeofparameter = Literal["string", "number", "boolean", "array", "object"]


# descrive che tipo è un parametro
class ParameterDefinition(BaseModel):
    type: typeofparameter


class CheckPrompt(BaseModel):
    prompt: str = Field(min_length=1, max_length=100)


# mi controlla i parametri in uscita da inserire nel messaggio di output
# ottengo un dizionario
class CheckOutputParameters(BaseModel):
    name: str = Field(min_length=1, max_length=50)
    prompt: str = Field(min_length=1, max_length=1000)
    parameters: dict[str, ParameterDefinition] = Field(min_length=1,
                                                       max_length=50)


class CheckFunctionsDefinition(BaseModel):
    name: str = Field(min_length=1, max_length=50)
    parameters: dict[str, ParameterDefinition]
    description: str = Field(min_length=1, max_length=1000)
    returns: ParameterDefinition

from pydantic import BaseModel, Field
from typing import Literal, Any

typeofparameter = Literal["string", "number", "boolean", "array", "object"]


class ParameterDefinition(BaseModel):
    type: typeofparameter


class CheckPrompt(BaseModel):
    prompt: str = Field(min_length=1)


class CheckOutputParameters(BaseModel):
    name: str = Field(min_length=1)
    prompt: str = Field(min_length=1)
    parameters: dict[str, Any] = Field(max_length=50)


class CheckFunctionsDefinition(BaseModel):
    name: str = Field(min_length=1)
    parameters: dict[str, ParameterDefinition]
    description: str = Field(min_length=1)
    returns: ParameterDefinition

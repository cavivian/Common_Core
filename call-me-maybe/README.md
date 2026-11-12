*This project has been created as part of the 42 curriculum by cavivian.*

# call me maybe

Introduction to function calling in LLMs.

## Description

This project is a function calling tool. It reads a natural language prompt
and it does **not** answer it. Instead, it chooses a function and its
arguments.

For example, with the prompt `What is the sum of 2 and 3?` the program does
not return `5`. It returns:

```json
{
    "prompt": "What is the sum of 2 and 3?",
    "name": "fn_add_numbers",
    "parameters": {"a": 2.0, "b": 3.0}
}
```

The model used is `Qwen/Qwen3-0.6B`. It is a very small model, so it is not
reliable if I only ask it to write JSON. To solve this problem I use
**constrained decoding**: at every step I block the tokens that would make
the output wrong, and the model can choose only between the tokens that are
left. In this way the output is always valid JSON that follows the schema of
the functions.

The goal is to reach a good accuracy with a small model, without using
libraries like `transformers`, `outlines` or `dspy` in our own code. The only
way I talk to the model is the `llm_sdk` package given with the subject.

### Main features

- Reads the functions and the prompts from JSON files.
- The function name is chosen by the model, not by rules or keywords.
- Supported parameter types: `number`, `string` and `boolean`.
- Numbers are written as `float`, like in the subject example.
- Clear error messages and no crash for missing or wrong input files.

## Instructions

### Requirements

- Python 3.10 or later
- [uv](https://docs.astral.sh/uv/)
- The `llm_sdk` folder, in the same directory as `src`

### Installation

```bash
make install     # runs uv sync
```

### Run

```bash
make run
```

This is the same as:

```bash
uv run python3 -m src
```

By default the program reads the files in `data/input/` and writes the result
in `data/output/function_calling_results.json`.

### Arguments

| Argument | Default | Meaning |
|---|---|---|
| `--functions_definition` | `data/input/functions_definition.json` | the available functions |
| `--input` | `data/input/function_calling_tests.json` | the prompts |
| `--output` | `data/output/function_calling_results.json` | the result file |
| `--model_name` | `Qwen/Qwen3-0.6B` | the model on the Hugging Face Hub |

### Other commands

| Command | What it does |
|---|---|
| `make debug` | runs the program with the Python debugger (pdb) |
| `make clean` | removes `__pycache__` and the cache of mypy |
| `make lint` | runs `flake8` and `mypy` with the flags of the subject |
| `make lint-strict` | runs `flake8` and `mypy --strict` |

## Example usage

Default files:

```bash
make run
```

Custom files:

```bash
uv run python3 -m src \
    --functions_definition data/input/functions_definition.json \
    --input data/input/function_calling_tests.json \
    --output data/output/function_calls.json
```

Example of output:

```json
[
    {
        "name": "fn_add_numbers",
        "prompt": "What is the sum of 2 and 3?",
        "parameters": {"a": 2.0, "b": 3.0}
    },
    {
        "name": "fn_reverse_string",
        "prompt": "Reverse the string 'hello'",
        "parameters": {"s": "hello"}
    },
    {
        "name": "fn_substitute_string_with_regex",
        "prompt": "Substitute the word 'cat' with 'dog' in 'The cat sat on the mat with another cat'",
        "parameters": {
            "source_string": "The cat sat on the mat with another cat",
            "regex": "cat",
            "replacement": "dog"
        }
    }
]
```

If an input file is missing or wrong, the program stops with one clear
message, for example:

```text
Invalid entry #0 in data/input/function_calling_tests.json: 'prompt': Field required
```

## Algorithm explanation

### Idea

A language model writes one token at a time. At every step it gives a score
(a *logit*) to every token of its vocabulary, and normally I take the token
with the highest score. With constrained decoding I change this step: before
the choice I set to `-inf` the score of every token that is not allowed.
A token with `-inf` can never be the maximum, so it is impossible to choose it.

The model only sees the list of token ids that I give to it. So the text
that I write ourselves is **added to this list as ids**. In this way the
model "reads" it and knows in which point of the JSON it is.

### Who writes what

The program writes the fixed parts of the JSON (braces, keys, quotes, commas).
The model writes only the parts that depend on the prompt: the name of the
function and the values of the parameters. For this reason a key can never be
wrong.

### Steps for every prompt

1. **Chat prompt.** The `llm_sdk` I received has no `format` method, so I
   write the chat format of Qwen3 by hand (system message with the functions
   in JSON, user message with the prompt, then the start of the assistant
   turn with an empty `<think>` block). I took the format from the official
   `chat_template` of the model.
2. **Tokenization.** The text is changed in token ids with `encode`.
3. **Vocabulary.** At the start I read the vocabulary file
   (`get_path_to_vocab_file`) and I build a map from token id to text. The
   symbols `Ġ` and `Ċ` of the tokenizer are changed in a space and a new line.
4. **Name of the function.** I add `{"name": "` to the list. At every step
   the allowed tokens are only the ones that keep the text as the beginning of
   a real function name. When the text is equal to a name, I stop.
5. **Parameters.** For every parameter of the chosen function:
   - I add the fixed text, for example `", "parameters": {"a": `;
   - the model writes the value, with a mask that depends on the type.
6. **Result.** The values are saved in a pydantic object and then all the
   results are written in the output file with `json.dump`.

### Masks for the values

- **number.** Only the tokens made of digits, `.` and `-` are allowed, and only
  if the text stays the beginning of a valid number (`-?\d+(\.\d+)?`). The
  end token (`,` or `}`, depending if it is the last parameter) is allowed
  only when the number is complete. So `-` or `2.` can never be the final
  number. After the generation the text is changed with `float`, and this is
  why I get `2.0` and not `2`.
- **string.** I allow all the tokens without a quote, a backslash or a
  control character. The string ends when the model chooses a token that
  contains a quote (for example `"`, `",` or `)",`). I keep the text that is
  before the quote, I throw away the rest, and I write the closing quote
  ourselves. At the end the ids are decoded with `decode`.
- **boolean.** The model must choose between `true` and `false`, with the same
  method used for the function name. The result is a real boolean.

### Why a set of ids for the masks

For every generated token I check about 150,000 positions with the question
"is this id allowed?". A `set` answers this question much faster than a list.
The sets with the digits, quotes and strings are built only once, before the
loops.

## Design decisions

- **Pydantic for all the classes.** The subject asks for it. I use it to
  validate the input files, and to build the result.
- **`Literal` for the parameter types.** A file with an unknown type is
  rejected when it is read, with a clear message.
- **`Any` for the values of the result.** The values can be numbers, strings or
  booleans, and a function can have different types. The cost is that pydantic
  does not check the types of the values, so I check them in the generation.
- **Own exceptions.** `InputFileError` and `OutputFileError` are raised by
  `files_handle.py`. The functions only report the problem, and `main` decides
  to print the message and exit with an error code.
- **Validation one entry at a time.** In this way the error message says which
  entry of the file is wrong.
- **The model is created once** and the vocabulary and the masks are built
  once, outside the loop on the prompts.
- **Constants at the top of the module.** `MAX_VALUE_TOKENS` and the regular
  expressions are constants and they are never changed while the program runs.
- **No private attributes of `llm_sdk`.** This is the reason why I write the
  chat format by hand: `apply_chat_template` needs the private attribute
  `_tokenizer`.
- **Strings without backslash and quotes inside.** It is simple and the JSON is
  always valid, but it has a limit (see below).

## Performance analysis

### Accuracy

On the 11 prompts of the example file, all the function names are correct,
and the numbers and the simple strings are correct. The three prompts with
regular expressions are the most difficult for a model of this size. In our
last run the regular expressions were reasonable, but one value was not
perfect: the replacement for the vowels has a space before the asterisk. So
our result is about 10 correct answers out of 11.

The quality depends a lot on the system message, so I tried to improve it
step by step and I counted the results again after every change.

### Speed

[FILL IN: total time of `time make run` on the 11 prompts, and the computer
used (CPU or GPU). The subject asks for less than 5 minutes.]

The model reads again all the prompt at every new token, because the SDK has
no cache. This is the main cost. For this reason I build the masks only once.

### Reliability

The structure of the JSON is written by the program, so the output file is
always valid JSON with the right keys. The types follow the definition of the
functions. Wrong or missing input files stop the program with a clear
message, and not with a traceback.

## Challenges faced

- **Tokens are not characters.** Many tokens contain more than one character
  and some start with a space (`Ġ`). I needed a map from id to text and I
  had to think about tokens, not letters.
- **Tokens that join more symbols.** At the end of a value the model wants to
  write tokens like `",` or `)",`, that contain the quote and other symbols.
  At first I allowed only the token `"` alone, and the model never closed the
  string: the regular expressions repeated the same part until the limit. I
  solved this when I accepted every token that contains a quote as the end of
  the string.
- **Chat format.** The SDK has no `format` method, so I had to read the chat
  template of Qwen3 and write the format by hand.
- **Objects and dictionaries.** At the beginning it was not clear when a value
  is a pydantic object (attribute with a dot) and when it is a dictionary.
  `json.dump` cannot write pydantic objects, so every result is changed with
  `model_dump()` before the writing.
- **Circular import.** The pydantic classes were in `__main__.py`, and this
  gave a circular import. I moved them in `models.py`.
- **Definition and result.** The type of a parameter in the definition
  (`{"type": "number"}`) is not the value in the result (`2.0`). The two
  things need different classes.

## Testing strategy

- I ran the 11 prompts of the example file and I read every result by hand.
- I checked the tokenization with a round trip: encode a text, decode the
  ids, and compare the two texts.
- While I were writing the masks I printed, at every step, the token that
  the model would choose without the mask and the token chosen with the mask.
  This is how I found the problem with the end of the strings.
- I ran a smaller input file with only the regular expression prompts, using
  the `--input` argument.
- I tested the errors of the input files (missing file, invalid JSON, wrong
  structure) and of the output (folder that does not exist).
- I run `flake8` and `mypy` with `make lint`.

## Limitations

- The types `array` and `object` are not supported. The program stops with an
  error message.
- A string cannot contain a backslash or a quote. For this reason a regular
  expression like `\d+` cannot be written, and the model has to use something
  like `[0-9]+`.
- If a function name is the beginning of another name (for example `fn_get` and
  `fn_get_square_root`), the shorter one is chosen first.
- The program is slow on a computer without a GPU, because the model reads the
  whole prompt at every token.

## Resources

### Documentation and references

- Qwen3-0.6B model card: <https://huggingface.co/Qwen/Qwen3-0.6B>
  (the `chat_template` inside `tokenizer_config.json` was our reference for
  the chat format)
- JSON specification: <https://www.json.org>
- Pydantic documentation: <https://docs.pydantic.dev>
- Python documentation for `re`, `argparse`, `pathlib` and `json`:
  <https://docs.python.org/3/>
- uv documentation: <https://docs.astral.sh/uv/>
- General articles and tutorials about tokenization (BPE) and about
  constrained decoding or structured generation with language models.

### How AI was used

I used Claude (Anthropic) as a tutor during the project.

- **Explanations.** Tokens, logits, the generation pipeline, constrained
  decoding, pydantic, type hints, `mypy` and `flake8`.
- **Guidance.** Step by step help to plan the project, with questions to
  understand every part before writing the code.
- **Review and debugging.** Claude read my code and the output of the
  program and showed errors, for example the wrong indentation of loops, the
  types of the variables, and the problem with the end of the strings.
- **README.** Claude helped to write this file. I checked the content.

I also discussed the project with other students of the school, who helped to
understand the general idea of the mechanism.

All the code that is in the repository was read, tested and understood by the
author.
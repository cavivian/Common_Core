PYTHON = python3 -m
MAIN = call_me_maybe.py
CONFIG = config.txt
export HF_HOME=/home/cavivian/sgoinfre/.hf_cache
export UV_CACHE_DIR=/home/cavivian/sgoinfre
export  export UV_PROJECT_ENVIRONMENT=/home/cavivian/sgoinfre/.venv

install:
	uv sync

run:
	uv run python3 -m src
#	$(PYTHON) $(MAIN) $(CONFIG)

debug:
	$(PYTHON) -m pdb $(MAIN) $(CONFIG)

clean:
	find . -type d -name "__pycache__" -exec rm -rf {} +
	find . -type d -name ".mypy_cache" -exec rm -rf {} +
	find . -type f -name "*.pyc" -delete
	find . -type d -name "*.egg-info" -exec rm -rf {} + 2>/dev/null; true
	find . -type f -name "maze.txt" -delete

lint:
	flake8 .
	mypy . --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

lint-strict:
	flake8 .
	mypy . --strict

build:
	pip install build
	python3 -m build

.PHONY: install run debug clean lint lint-strict build
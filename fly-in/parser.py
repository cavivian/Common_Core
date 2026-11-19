# cosa devo fare:
# - try-except in cui leggo i file dei percorsi(basta farlo con sys)
# - fare il parse di tutti i file (sempre dentro il try, di quello che
# viene passato in input)
import re
from typing import Any


COMPLETE_STRUCTURE = r"""(?:hub|start_hub|end_hub):\s
                         (?P<name>[^\s-]+)
                         \s(?P<x>-?\d+)\s
                         (?P<y>-?\d+)
                         (?:\s\[(?P<tags>\w+=\w+(?:\s\w+=\w+)*)\])?"""
CONNECTIONS = r"""(?:connection):\s(?P<connections>\w+-\w+)\s?
                  (\[(?P<tags>\w+=\d+)\])?"""


class Parse:
    def __init__(self, path: str) -> None:
        self.path = path
        self.connections = []
        self.zone = []
        # print(self.path)

    def open(self):
        with open(self.path, 'r') as f:
            for i, line in enumerate(f, start=1):
                self.correct_format(line)
                # print(f"I'm {line} at index {i}")
    # in questa funzione non sto salvando l'indice o il nome di dove

    # trovo l'errore
    def correct_format(self, content: str) -> str:
        self.line = content.strip()
        if not self.line.startswith('#') or "":
            match = re.fullmatch(COMPLETE_STRUCTURE, self.line, re.VERBOSE)
            match_connections = re.fullmatch(CONNECTIONS, self.line,
                                             re.VERBOSE)
            if match:
                result = match.groupdict()
                self.zone.append(result)
                # print(f"Zone results: {result}")
            elif match_connections:
                result = match_connections.groupdict()
                self.connections.append(result)
                # print(f"Connection results: {result}")
            else:
                print(f"There's a problem at line {self}")

    # def create_a_dict(self, zone: list[str], connections: list[str]):


# if self.lines.startswith('#'):
        #     pass
        #     # cast_to_dict = dict(value.split(':') for value
        # in content.split('\n'))
        # else:
        #     key_dict = self.search_before_dots()
        #     print(key_dict)
        #         # cast_to_dict = dict(value.split(':') for value in
        # self.lines[i].split('\n'))
        #         # print(f"il tipo di cast_to_dict e': {type(cast_to_dict)}")
        #         # print(f" voglio stampare il secondo
        # elemento:'{self.lines[i]}'")
        #     # print(len(self.lines[i]))
        # # print(f"il tipo di lines è: {type(self.lines)}")

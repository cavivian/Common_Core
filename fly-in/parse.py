# cosa devo fare:
# - try-except in cui leggo i file dei percorsi(basta farlo con sys)
# - fare il parse di tutti i file (sempre dentro il try, di quello che
# viene passato in input)
import re
from typing import Any

DRONES = r"(?:nb_drones):\s(?P<numbers>\d+)"
COMPLETE_STRUCTURE = r"""(?P<kind>hub|start_hub|end_hub):\s
                         (?P<name>[^\s-]+)
                         \s(?P<x>-?\d+)\s
                         (?P<y>-?\d+)
                         (?:\s\[(?P<tags>\w+=[^\s=\[\]]+(?:\s\w+=[^\s=\[\]]+)*)
                         \])?"""
CONNECTIONS = r"""(?:connection):\s
                  (?P<zone1>[^\s\-\[\]]+)-(?P<zone2>[^\s\-\[\]]+)
                  (?:\s\[(?P<tags>\w+=[^\s=\[\]]+(?:\s\w+=[^\s=\[\]]+)*)\])?"""
ZONE_DEFAULTS: dict[str, str] = {"zone": "normal", "max_drones": "1"}
LINK_DEFAULTS: dict[str, str] = {"max_link_capacity": "1"}
VALID_ZONES = {"normal", "blocked", "restricted", "priority"}


class ParseError(Exception):
    def __init__(self, index: int, cause: str):
        self.index = index
        self.cause = cause
        super().__init__(f"line {index}: {cause}")


class Parse:
    def __init__(self, path: str) -> None:
        self.path = path
        self.connections = []
        self.zone = []
        self.nb_drones: int | None = None

    def open(self):
        with open(self.path, 'r') as f:
            for i, line in enumerate(f, start=1):
                try:
                    self.correct_format(line)
                except ValueError as e:
                    raise ParseError(i, str(e)) from e
            self.check_all()
            # print(f"I'm {line} at index {i}")
    # in questa funzione non sto salvando l'indice o il nome di dove

    # trovo l'errore
    def correct_format(self, content: str) -> str:
        self.line = content.strip()
        if self.line.startswith('#') or self.line == "":
            pass
        else:
            match_drones = re.fullmatch(DRONES, self.line, re.VERBOSE)
            match = re.fullmatch(COMPLETE_STRUCTURE, self.line, re.VERBOSE)
            match_connections = re.fullmatch(CONNECTIONS, self.line,
                                             re.VERBOSE)
            if match_drones:
                result = match_drones.groupdict()
                # self.drones.append(result)
                result['numbers'] = int(result['numbers'])
                if result['numbers'] <= 0:
                    raise ValueError("nb_drones must be positive")
                if self.nb_drones is not None:
                    raise ValueError("nb_drones defined more than once")
                self.nb_drones = result['numbers']
                # print(f"i'm here {result}")
                # print(type(result['numbers']))
            elif match:
                result = match.groupdict()
                # print(result)
                result['tags'] = self.give_default(self.create_a_dict(
                    result['tags']), ZONE_DEFAULTS)
                result['x'] = int(result['x'])
                result['y'] = int(result['y'])
                result['tags']['max_drones'] = int(result['tags']
                                                   ['max_drones'])
                if result['tags']['zone'] not in VALID_ZONES:
                    raise ValueError(f"""invalid zone type '{result['tags']
                                                           ['zone']}'""")
                if result['tags']['max_drones'] <= 0:
                    raise ValueError("max_drones must be positive")
                self.zone.append(result)
                # print(result['x'])
                # print(type(result['x']))
                # print(f"Zone results: {result}")
            elif match_connections:
                result = match_connections.groupdict()
                result['tags'] = self.give_default(self.create_a_dict(
                    result['tags']), LINK_DEFAULTS)
                result['tags']['max_link_capacity'] = int(result['tags']
                                                          ['max_link_capacity']
                                                          )
                if result['tags']['max_link_capacity'] <= 0:
                    raise ValueError("max_link_capacity must be positive")
                self.connections.append(result)
                # print(f"Connection results: {result}")
            else:
                raise ValueError(f"invalid line: '{self.line}'")

    def check_all(self) -> None:
        if self.nb_drones is None:
            raise ValueError("nb_drones is missing")
        names: set[str] = set()
        for z in self.zone:
            if z['name'] in names:
                raise ValueError(f"duplicate zone name '{z['name']}'")
            names.add(z['name'])
        kinds = [z['kind'] for z in self.zone]
        if kinds.count('start_hub') != 1:
            raise ValueError("there must be exactly one start_hub")
        if kinds.count('end_hub') != 1:
            raise ValueError("there must be exactly one end_hub")
        links: set[frozenset[str]] = set()
        for c in self.connections:
            for name in (c['zone1'], c['zone2']):
                if name not in names:
                    raise ValueError(f"connection uses unknown zone '{name}'")
            key = frozenset((c['zone1'], c['zone2']))
            if key in links:
                raise ValueError(
                    f"duplicate connection {c['zone1']}-{c['zone2']}")
            links.add(key)

    def create_a_dict(self, tags: str | None) -> dict[str, Any]:
        storage = {}
        if tags is None:
            return storage
        # print(tags)
        if tags == 'numbers':
            for line in tags.split():
                key, value = line.split(':')
                storage[key] = value
        for line in tags.split():
            key, value = line.split('=')
            storage[key] = value
        # print(storage)
        return (storage)

    def give_default(self, storage: dict[str, Any],
                     defaults: dict[str, Any]) -> dict[str, str]:
        """Add the missing keys of `storage`, using `defaults`."""
        for key, value in defaults.items():
            storage.setdefault(key, value)
        return storage

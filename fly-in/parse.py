import re
from classes import Zone, ZoneType, ZoneStatus, Connection

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
    """This class raise the errors of the program, and displays the line
    and the problem"""
    def __init__(self, index: int, cause: str) -> None:
        self.index = index
        self.cause = cause
        super().__init__(f"line {index}: {cause}")


class Parsing:
    """This class checks that every line of
    the file given is written correctly"""
    def __init__(self, path: str) -> None:
        self.path = path
        self.connections: list[Connection] = []
        self.zone: list[Zone] = []
        self.nb_drones: int | None = None

    def open(self) -> None:
        """ Function that opens the map"""
        with open(self.path, 'r') as f:
            for i, line in enumerate(f, start=1):
                try:
                    self.correct_format(line)
                except ValueError as e:
                    raise ParseError(i, str(e)) from e
            self.check_all()

    def correct_format(self, content: str) -> None:
        """ Function that checks if the format is correct, like:
        - if nb_drones is the first info
        - if the zones and connection syntax is correct
            - if not the program raise an error"""
        self.line = content.strip()
        if self.line.startswith('#') or self.line == "":
            pass
        else:
            match_drones = re.fullmatch(DRONES, self.line, re.VERBOSE)
            match = re.fullmatch(COMPLETE_STRUCTURE, self.line, re.VERBOSE)
            match_connections = re.fullmatch(CONNECTIONS, self.line,
                                             re.VERBOSE)
            if (match or match_connections) and self.nb_drones is None:
                raise ValueError("nb_drones must be defined "
                                 "before zones and connections")
            if match_drones:
                self.drones_match(match_drones)
            elif match:
                self.match_zones(match)
            elif match_connections:
                self.connections_match(match_connections)
            else:
                raise ValueError(f"invalid line: '{self.line}'")

    def drones_match(self, match_drones: re.Match[str]) -> None:
        """ Function that checks that the number of drones is positive, and if
        it can be an int, else raise an error"""
        nb_drones = int(match_drones.group('numbers'))
        if nb_drones <= 0:
            raise ValueError("nb_drones must be positive")
        if self.nb_drones is not None:
            raise ValueError("nb_drones defined more than once")
        self.nb_drones = nb_drones

    def match_zones(self, match: re.Match[str]) -> None:
        """ This checks that the zones are written correctly"""
        result = match.groupdict()
        tags = self.give_default(self.create_a_dict(result['tags']),
                                 ZONE_DEFAULTS)
        x = int(result['x'])
        y = int(result['y'])
        try:
            max_drones = int(tags['max_drones'])
        except ValueError as e:
            raise ValueError("max_drones must be an integer") from e
        if tags['zone'] not in VALID_ZONES:
            raise ValueError(f"invalid zone type '{tags['zone']}'")
        if max_drones <= 0:
            raise ValueError("max_drones must be positive")
        if any(z.name == result['name'] for z in self.zone):
            raise ValueError(f"duplicate zone name '{result['name']}'")
        self.zone.append(Zone(name=result['name'], x=x, y=y,
                              typezone=ZoneType(tags['zone']),
                              color=tags.get('color'),
                              max_drones=max_drones,
                              status=ZoneStatus(result['kind'])))

    def connections_match(self, match_connections: re.Match[str]) -> None:
        """ This checks that the connection are written correctly"""
        result = match_connections.groupdict()
        tags = self.give_default(self.create_a_dict(result['tags']),
                                 LINK_DEFAULTS)
        try:
            capacity = int(tags['max_link_capacity'])
        except ValueError as e:
            raise ValueError("max_link_capacity must be an integer.") from e
        if capacity <= 0:
            raise ValueError("max_link_capacity must be positive")
        if result['zone1'] == result['zone2']:
            raise ValueError("connection links zone "
                             f"'{result['zone1']}' to itself")
        known = {z.name for z in self.zone}
        for name in (result['zone1'], result['zone2']):
            if name not in known:
                raise ValueError(f"connection uses unknown zone '{name}'")
        key = frozenset((result['zone1'], result['zone2']))
        if any(frozenset((c.zone1, c.zone2)) == key
               for c in self.connections):
            raise ValueError(f"duplicate connection "
                             f"{result['zone1']}-{result['zone2']}")
        self.connections.append(Connection(zone1=result['zone1'],
                                           zone2=result['zone2'],
                                           max_link_capacity=capacity))

    def check_all(self) -> None:
        """ This is an ultimate check,
        Run the final checks on the whole file"""
        if self.nb_drones is None:
            raise ValueError("nb_drones is missing")
        kinds = [z.status for z in self.zone]
        if kinds.count(ZoneStatus.START_HUB) != 1:
            raise ValueError("there must be exactly one start_hub")
        if kinds.count(ZoneStatus.END_HUB) != 1:
            raise ValueError("there must be exactly one end_hub")

    def create_a_dict(self, tags: str | None) -> dict[str, str]:
        """ This creates a dict for every key-value pair"""
        storage: dict[str, str] = {}
        if tags is None:
            return storage
        for line in tags.split():
            key, value = line.split('=')
            if key in storage:
                raise ValueError(f"duplicate tag '{key}'")
            storage[key] = value
        return storage

    def give_default(self, storage: dict[str, str],
                     defaults: dict[str, str]) -> dict[str, str]:
        """Add the missing keys of `storage`, using `defaults`."""
        for key, value in defaults.items():
            storage.setdefault(key, value)
        return storage
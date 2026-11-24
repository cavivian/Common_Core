from enum import Enum


class ZoneType(Enum):
    """Creation of enum variables for zone type"""
    RESTRICTED = "restricted"
    NORMAL = "normal"
    BLOCKED = "blocked"
    PRIORITY = "priority"


class ZoneStatus(Enum):
    """Create of enum variables for simulation drone status"""
    START_HUB = "start_hub"
    END_HUB = "end_hub"
    HUB = "hub"


class Drone:
    """This class represents the info about a Drone"""

    def __init__(self, drone_id: int, start: str) -> None:
        self.drone_id = drone_id  # indice del drone
        self.zone: str = start  # mi dice il nome della zona in cui si trova
        self.connection: str | None = None
        # ^ mi dice il nome della connessione in cui si trova

    def go(self, update: str) -> None:
        """Updating the zone name when the drone moves on"""
        self.zone = update

    def go_to_connection_from_zone(self, update_connection: str) -> None:
        """Updating the connection name when the drone moves on"""
        self.connection = update_connection

    def go_to_zone(self, update_zone: str) -> None:
        """Updating the zone name and resets connection name to
        None when the drone moves on"""
        self.zone = update_zone
        self.connection = None


class Fleet:
    """Hold all the drones and tell if they have all reached the end."""

    def __init__(self, start_zone: str, nb_drones: int,
                 end_zone: str) -> None:
        self.start_zone = start_zone
        self.nb_drones = nb_drones
        self.end_zone = end_zone
        self.drones: list[Drone] = []
        self.create_list_of_class_drones()

    def create_list_of_class_drones(self) -> None:
        """Create one Drone for each id, from 1 to nb_drones."""
        for drone_id in range(1, self.nb_drones + 1):
            self.drones.append(Drone(drone_id, self.start_zone))

    def check_if_end(self) -> bool:
        """Return True if every drone is in the end zone."""
        return all(d.zone == self.end_zone for d in self.drones)


class Zone:
    """Class that creates the zones"""

    def __init__(self, name: str,
                 x: int, y: int,
                 typezone: ZoneType,
                 color: str | None,
                 max_drones: int,
                 status: ZoneStatus
                 ) -> None:
        self.name = name
        self.x = x
        self.y = y
        self.typezone = typezone
        self.color = color
        self.max_drones = max_drones
        self.status = status

    def is_blocked(self) -> bool:
        """Return True if drones can never enter this zone."""
        return self.typezone == ZoneType.BLOCKED

    def move_cost(self) -> int:
        """Return how many turns a drone needs to enter this zone."""
        if self.typezone == ZoneType.RESTRICTED:
            return 2
        return 1

    def has_room(self, drones_inside: int) -> bool:
        """Return True if one more drone can be in the zone.

        Start and end zones have no limit."""
        if self.status != ZoneStatus.HUB:
            return True
        return drones_inside < self.max_drones


class Connection:
    """Class that connects the zone without repetitions of zone's name"""

    def __init__(self, zone1: str,
                 zone2: str,
                 max_link_capacity: int,
                 ) -> None:
        self.zone1 = zone1
        self.max_link_capacity = max_link_capacity
        self.zone2 = zone2

    def other_end(self, zone: str) -> str:
        """Return the zone at the opposite end of the connection."""
        if zone == self.zone1:
            return self.zone2
        if zone == self.zone2:
            return self.zone1
        raise ValueError(f"'{zone}' is not part of this connection")

    def has_room(self, drones_on_link: int) -> bool:
        """Return True if one more drone can use this connection."""
        return drones_on_link < self.max_link_capacity

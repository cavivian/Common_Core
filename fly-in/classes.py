from enum import Enum

class ZoneType(Enum):
    """Creation of enum variables for zone type"""
    RESTRICTED = "restricted"
    NORMAL = "normal"
    BLOCKED = "blocked"
    PRIORITY = "priority"


class DroneStatus(Enum):
    """Create of enum variables for simulation drone status"""
    START = "start"
    END = "end"
    NORMAL = "normal"

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


class Zones:
    def __init__(self, zones_name: str, c_x: int, c_y: int, typezone: ZoneType, color: str, max_drones: int, status: DroneStatus) -> None:
        self.zones_name = zones_name
        self.c_x = c_x
        self.c_y = c_y
        self.typezone = typezone
        self.color = color
        self.max_drones = max_drones
        self.status = status



class Connections:
    def __init__(self, connections):
        self.connections = connections
        pass

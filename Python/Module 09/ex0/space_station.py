from pydantic import BaseModel, Field
from datetime import datetime
from typing import Optional


class space_station(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    note: Optional[str] = Field(default=None, max_length=200)



if __name__ == "__main__":
    print("Space Station Data Validation")
    print("========================================")
    assegna = space_station(
                            station_id = "ISS001",
                            name = "International Space Station",
                            crew_size = 6,
                            power_level = 85.5,
                            oxygen_level = 92.3,
                            last_maintenance = "2026-06-22",
                            is_operational = True
                            )
    print("Valid Station Created:")
    print(f"ID: {assegna.station_id}")
    print(f"Name: {assegna.name}")
    print(f"Crew: {assegna.crew_size} people")
    print(f"Power: {assegna.power_level}%")
    print(f"Oxygen: {assegna.oxygen_level}%")
    if assegna.is_operational is True:
        print("Status: Operational")
    else:
        print("Non va")
    print()
    print("========================================")
    try:
        sbagliato = space_station(
                            station_id = "ISS001",
                            name = "International Space Station",
                            crew_size = 40,
                            power_level = 85.5,
                            oxygen_level = 92.3,
                            last_maintenance = "2026-06-22",
                            is_operational = True
                            )
    except Exception as e:
        print("Expected Validation Error:")
        for err in e.errors():
            print(err['msg'])
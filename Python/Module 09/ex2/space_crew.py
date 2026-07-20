from pydantic import BaseModel, model_validator, Field
from enum import Enum
from datetime import datetime


class Rank(Enum):
    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class Crewmember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[Crewmember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default="planned")
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def verifica(self) -> str:
        if not self.mission_id.startswith("M"):
            raise ValueError("Mission ID must start with 'M'")
        ha_leader = any(membro.rank in (Rank.COMMANDER, Rank.CAPTAIN)
                        for membro in self.crew)
        if not ha_leader:
            raise ValueError("Must have at least one Commander or Captain")
        missione = self.duration_days > 365
        if missione:
            esperti = 0
            for membro in self.crew:
                if membro.years_experience >= 5:
                    esperti += 1
            perc = (len(self.crew) / esperti) * 100
            if perc < 50:
                raise ValueError("Long missions (> 365 days) need 50% "
                                 "experienced crew (5+ years)")
        for member in self.crew:
            if not member.is_active:
                raise ValueError("All crew members must be active")
        return (self)


if __name__ == "__main__":
    sarah = Crewmember(
        member_id="123",
        name="Sarah Connor",
        rank=Rank.COMMANDER,
        age=20,
        specialization="Mission Command",
        years_experience=5,
        is_active=True
    )
    john = Crewmember(
        member_id="125",
        name="John Smith",
        rank=Rank.LIEUTENANT,
        age=30,
        specialization="Navigation",
        years_experience=37,
        is_active=True
    )
    alice = Crewmember(
        member_id="123",
        name="Alice Johnson",
        rank=Rank.OFFICER,
        age=20,
        specialization="Engineering",
        years_experience=18,
        is_active=True
    )
    mission = SpaceMission(
        mission_id="M2024_MARS",
        mission_name="Mars Colony Establishment",
        destination="Mars",
        launch_date="2026-04-21",
        duration_days=900,
        crew=[sarah, john, alice],
        budget_millions=2500.0
    )

    print("Valid Mission Created:")
    print("=========================================")
    print()
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(mission.crew)}")
    print("Crew members:")
    for member in mission.crew:
        print(f"- {member.name} ({member.rank.value}) -"
              f" {member.specialization}")
    print("=========================================")
    try:
        sbagliato = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date="2026-04-21",
            duration_days=900,
            crew=[alice],
            budget_millions=2500.0
            )
    except Exception as e:
        print("Expected Validation Error:")
        for err in e.errors():
            print(err['msg'])

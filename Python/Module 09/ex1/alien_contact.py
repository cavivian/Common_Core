from pydantic import BaseModel, Field, model_validator
from enum import Enum
from datetime import datetime
from typing import Optional


class ContactType(Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class aliencontact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: Optional[str] = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode='after')
    def verifica(self) -> str:
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")
        phisico = self.contact_type == self.contact_type.PHYSICAL
        veri = self.is_verified
        if not phisico and veri:
            raise ValueError("Physical contact reports must be verified")
        tele = self.contact_type == self.contact_type.TELEPATHIC
        testimoni = self.witness_count
        if tele and testimoni < 3:
            raise ValueError("Telepathic contact requires at least "
                             "3 witnesses")
        segnale = self.signal_strength
        mess = self.message_received
        if segnale <= 7.0 and mess is None:
            raise ValueError("Strong signals (> 7.0) should "
                             "include received messages")
        return (self)


if __name__ == "__main__":
    print("Alien Contact Log Validation")
    print("======================================")
    assegna = aliencontact(
        contact_id="AC_2024_001",
        timestamp="2026-06-22",
        location="Area 51, Nevada",
        contact_type=ContactType.RADIO,
        signal_strength=8.5,
        duration_minutes=45,
        witness_count=5,
        message_received="Greetings from Zeta Reticuli",
        is_verified=True
    )
    print("Valid contact report:")
    print(f"ID: {assegna.contact_id}")
    print(f"Type: {assegna.contact_type.value}")
    print(f"Location: {assegna.location}")
    print(f"Signal: {assegna.signal_strength}/10")
    print(f"Duration: {assegna.duration_minutes} minutes")
    print(f"Witnesses: {assegna.witness_count}")
    print(f"Message: '{assegna.message_received}'")
    print()
    print("======================================")
    try:
        sbagliato = aliencontact(
            contact_id="AC_2024_001",
            timestamp="2026-06-22",
            location="Area 51, Nevada",
            contact_type=ContactType.TELEPATHIC,
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=2,
            message_received="Greetings from Zeta Reticuli",
            is_verified=True
            )
    except Exception as e:
        print("Expected Validation Error:")
        for err in e.errors():
            print(err['msg'])

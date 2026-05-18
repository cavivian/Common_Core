from abc import ABC, abstractmethod
from typing import Any, Tuple

class DataProcessor(ABC):
	def __init__(self, value):
		super().__init__()
	@abstractmethod
	def validate(self, data: Any) -> bool:  # controlla che i dati di input siano appropriati per il dato corrente
		pass
	@abstractmethod
	def ingest(self, data: Any) -> None:  # processa i dati di input
		pass
	def output(self) -> Tuple[int, str]:  # prende il dato memorizzato piu' vecchio e lo rimuove
		pass

class NumericProcessor(DataProcessor):  # si occupa di controllare che i dati siano numeri 
	pass


class TextProcessor(DataProcessor):  # si occupa di controllare che i dati siano stringhe
	pass


class LogProcessor(DataProcessor):  # si occupa di convertire i dati di un dict in str
	pass


def main():
	print("=== Code Nexus - Data Processor ===")
	print("\nTesting Numeric Processor...")

	pass


if __name__ == "__main__":
	main()

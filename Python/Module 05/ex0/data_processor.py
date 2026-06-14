from abc import ABC, abstractmethod
from typing import Any, List, Union, Dict

class DataProcessor(ABC):
    def __init__(self) -> None:
        # Usiamo una lista per mantenere l'ordine FIFO (First-In, First-Out)
        # Ogni elemento salvato sarà una tupla: (rank_di_elaborazione, stringa_dati)
        self._storage: List[tuple[int, str]] = []  # contiene tutti i dati, è una variabile privata
        self._counter: int = 0  # contatore che incrementa ogni volta che aggiungiamo un dato

    @abstractmethod
    def validate(self, data: Any) -> bool:
        # Verifica se i dati in input sono appropriati per questo processore.
        pass  # pass perchè la logica è diversa per ogni processore, uno è un testo, un altro un numero ecc.

    @abstractmethod
    def ingest(self, data: Any) -> None:
        # Elabora e memorizza i dati in input.
        pass  # stessa cosa del validate

    def output(self) -> tuple[int, str]:
        # Estrae e rimuove l'elemento più vecchio memorizzato internamente.
        if not self._storage:
            raise IndexError("No data available to output")
        return self._storage.pop(0)
		# pop(0) perchè prende l'elemento più vecchio memorizzato e lo elimina


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        # type(x) in (int, float) evita che i booleani (True/False) vengano scambiati per numeri
        if type(data) in (int, float):  # la lista deve contenere solo int e float, il type invece controlla ceh sia perfettamente matchato
            return True  # se la lista contiene solo int e float ritorna True
        if isinstance(data, list):  # controlla che sia un'istanza della classe specificata
            return all(type(x) in (int, float) for x in data)
        return False

    def ingest(self, data: Union[int, float, List[Union[int, float]]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        
        if isinstance(data, list):
            for item in data:
                self._storage.append((self._counter, str(item)))
                self._counter += 1
        else:
            self._storage.append((self._counter, str(data)))
            self._counter += 1


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):  # se è una lista di stringhe ritorniamo true
            return all(isinstance(x, str) for x in data)
        return False

    def ingest(self, data: Union[str, List[str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        
        if isinstance(data, list):
            for item in data:
                self._storage.append((self._counter, item))
                self._counter += 1
        else:
            self._storage.append((self._counter, data))
            self._counter += 1


class LogProcessor(DataProcessor):  # si occupa dei dizionari
    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return all(isinstance(k, str) and isinstance(v, str) for k, v in data.items())
        if isinstance(data, list):
            return all(isinstance(x, dict) and all(isinstance(k, str) and isinstance(v, str) for k, v in x.items()) for x in data)
        return False

    def ingest(self, data: Union[Dict[str, str], List[Dict[str, str]]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        
        if isinstance(data, list):
            for item in data:
                log_str = f"{item.get('log_level', '')}: {item.get('log_message', '')}"
                self._storage.append((self._counter, log_str))
                self._counter += 1
        else:
            log_str = f"{data.get('log_level', '')}: {data.get('log_message', '')}"
            self._storage.append((self._counter, log_str))
            self._counter += 1


# --- Sezione di Test ---
if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")

    # 1. Test Numeric Processor
    print("\nTesting Numeric Processor...")
    num_proc = NumericProcessor()
    print(f"Trying to validate input '42': {num_proc.validate(42)}")
    print(f"Trying to validate input 'Hello': {num_proc.validate('Hello')}")
    
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        # Questa riga causerà volutamente il warning di mypy perché 'foo' è una stringa,
        # ma NumericProcessor.ingest si aspetta int, float o liste di essi.
        num_proc.ingest('foo')  
    except ValueError as e:
        print(f"Got exception: {e}")

    data_num = [1, 2, 3, 4, 5]
    print(f"Processing data: {data_num}")
    num_proc.ingest(data_num)
    
    print("Extracting 3 values...")
    for _ in range(3):
        rank, val = num_proc.output()
        print(f"Numeric value {rank}: {val}")

    # 2. Test Text Processor
    print("\nTesting Text Processor...")
    text_proc = TextProcessor()
    print(f"Trying to validate input '42': {text_proc.validate(42)}")
    
    data_text = ['Hello', 'Nexus', 'World']
    print(f"Processing data: {data_text}")
    text_proc.ingest(data_text)
    
    print("Extracting 1 value...")
    rank, val = text_proc.output()
    print(f"Text value {rank}: {val}")

    # 3. Test Log Processor
    print("\nTesting Log Processor...")
    log_proc = LogProcessor()
    print(f"Trying to validate input 'Hello': {log_proc.validate('Hello')}")
    
    data_log = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ]
    print(f"Processing data: {data_log}")
    log_proc.ingest(data_log)
    
    print("Extracting 2 values...")
    for _ in range(2):
        rank, val = log_proc.output()
        print(f"Log entry {rank}: {val}")
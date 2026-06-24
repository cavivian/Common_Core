from abc import ABC, abstractmethod
from typing import Protocol, Tuple, List
import typing


class ExportPlugin(Protocol):
    def process_output(self, data: List[Tuple[int, str]]) -> None:
        pass


class CSVExportPlugin:
    def process_output(self, data: List[Tuple[int, str]]) -> None:
        if not data:
            return
        print("CSV Output:")
        print(",".join(item[1] for item in data) + "\n")


class JSONExportPlugin:
    def process_output(self, data: List[Tuple[int, str]]) -> None:
        if not data:
            return
        print("JSON Output:")
        # Generazione manuale della stringa dizionario mantenendo i contatori originari
        voci = ", ".join(f'"item_{item[0]}": "{item[1]}"' for item in data)
        print(f"{{{voci}}}")


class DataProcessor(ABC):
    def __init__(self, processor_name: str) -> None:
        self.processor_name = processor_name
        self._storage: list[tuple[int, str]] = []
        self._counter: int = 0

    @abstractmethod
    def validate(self, data: typing.Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: typing.Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._storage:
            raise IndexError("No data available to output")
        return self._storage.pop(0)


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__("Numeric Processor")

    def validate(self, data: typing.Any) -> bool:
        if type(data) in (int, float):
            return True
        if isinstance(data, list):
            return all(type(x) in (int, float) for x in data)
        return False

    def ingest(self, data: typing.Union[int, float, list[typing.Union[int, float]]]) -> None:
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
    def __init__(self) -> None:
        super().__init__("Text Processor")

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            return all(isinstance(x, str) for x in data)
        return False

    def ingest(self, data: typing.Union[str, list[str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        
        if isinstance(data, list):
            for item in data:
                self._storage.append((self._counter, item))
                self._counter += 1
        else:
            self._storage.append((self._counter, data))
            self._counter += 1


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        super().__init__("Log Processor")

    def validate(self, data: typing.Any) -> bool:
        if isinstance(data, dict):
            return all(isinstance(k, str) and isinstance(v, str) for k, v in data.items())
        if isinstance(data, list):
            return all(isinstance(x, dict) and all(isinstance(k, str) and isinstance(v, str) for k, v in x.items()) for x in data)
        return False

    def ingest(self, data: typing.Union[dict[str, str], list[dict[str, str]]]) -> None:
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


class DataStream:
    def __init__(self) -> None:
        # Lista che conterrà i processori registrati
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        # Aggiunge un nuovo processore alla lista dei processori attivi.
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        # Analizza ogni elemento della lista e lo assegna al primo processore compatibile.
        for element in stream:
            handled = False
            for proc in self.processors:
                # Chiamata polimorfica a validate
                if proc.validate(element):
                    proc.ingest(element)
                    handled = True
                    break # Elemento gestito, passa al prossimo elemento dello stream
            if not handled:
                print(f"DataStream error - Can't process element in stream: {element}")

    def print_processors_stats(self) -> None:
        # Stampa le statistiche di tutti i processori registrati.
        print("\n== DataStream statistics ==")
        if not self.processors:
            print("No processor found, no data")
            return

        for proc in self.processors:
            print(f"{proc.processor_name}: total {proc._counter} items processed, remaining {len(proc._storage)} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self.processors:  #per ogni processore registrato consuma fino a nb elementi se disponibili
            extracted_data = []
            for _ in range(nb):
                try:
                    item = proc.output()
                    extracted_data.append(item)
                except IndexError:
                    break # se lo storage del processore si svuota prima di arrivare a 'nb', si ferma
            plugin.process_output(extracted_data)  # passa la lista di tuple estratte al plugin corrente




if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ===")
    
    print("\nInitialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()

    print("\nRegistering Processor")
    num_processor = NumericProcessor()
    text_processor = TextProcessor()
    log_processor = LogProcessor()

    stream.register_processor(num_processor)
    stream.register_processor(text_processor)
    stream.register_processor(log_processor)

    # Il lotto di dati misti fornito dall'esempio
    batch_data_1 = [
        'Hello world', 
        [3.14, -1, 2.71], 
        [
            {'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'}, 
            {'log_level': 'INFO', 'log_message': 'User wil is connected'}
        ], 
        42, 
        ['Hi', 'five']
    ]

    print(f"\nSend first batch of data on stream: {batch_data_1}")
    stream.process_stream(batch_data_1)
    stream.print_processors_stats()

    print("\nSend 3 processed data from each processor to a CSV plugin:\n")
    csv_plugin = CSVExportPlugin()
    stream.output_pipeline(3, csv_plugin)
    stream.print_processors_stats
    
    batch_data_2 = [
        21,
        ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
        [
            {'log_level': 'ERROR', 'log_message': '500 server crash'},
            {'log_level': 'NOTICE', 'log_message': 'Certificate expires in 10 days'}
        ],
        [32, 42, 64, 84, 128, 168],
        'World hello'
    ]

    print(f"\nSend another batch of data: {batch_data_2}")
    stream.process_stream(batch_data_2)
    stream.print_processors_stats()

    print("\nSend 5 processed data from each processor to a JSON plugin:\n")
    json_plugin = JSONExportPlugin()
    stream.output_pipeline(5, json_plugin)
    stream.print_processors_stats()
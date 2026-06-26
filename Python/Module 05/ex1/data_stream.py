from abc import ABC, abstractmethod
import typing


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

    def ingest(self, data: typing.Union[int, float]) -> None:
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
            return all(isinstance(k, str) and
                       isinstance(v, str)
                       for k, v in data.items())
        if isinstance(data, list):
            return all(isinstance(x, dict) and
                       all(isinstance(k, str) and
                           isinstance(v, str)
                           for k, v in x.items()) for x in data)
        return False

    def ingest(self, data: typing.Union[dict[str, str],
                                        list[dict[str, str]]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")

        if isinstance(data, list):
            for item in data:
                log_str = f"{item.get('log_level', '')}:"
                f" {item.get('log_message', '')}"
                self._storage.append((self._counter, log_str))
                self._counter += 1
        else:
            log_str = f"{data.get('log_level', '')}:"
            f" {data.get('log_message', '')}"
            self._storage.append((self._counter, log_str))
            self._counter += 1


# --- Nuova Classe DataStream ---
class DataStream:
    def __init__(self) -> None:
        # Lista che conterrà i processori registrati
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        # Aggiunge un nuovo processore alla lista dei processori attivi.
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        # Analizza ogni elemento della lista e lo
        # assegna al primo processore compatibile.
        for element in stream:
            handled = False
            for proc in self.processors:
                # Chiamata polimorfica a validate
                if proc.validate(element):
                    proc.ingest(element)
                    handled = True
                    break  # Elemento gestito, passa al
                # prossimo elemento della lista

            if not handled:
                print(f"DataStream error - Can't process "
                      f"element in stream: {element}")

    def print_processors_stats(self) -> None:
        # Stampa le statistiche di tutti i processori registrati.
        print("== DataStream statistics ==")
        if not self.processors:
            print("No processor found, no data")
            return

        for proc in self.processors:
            print(f"{proc.processor_name}: total "
                  f"{proc._counter} items processed, remaining "
                  f"{len(proc._storage)} on processor"
                  )


# --- Scenario di Test ---
if __name__ == "__main__":
    print("=== Code Nexus - Data Stream ===")

    print("\nInitialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()

    print("\nRegistering Numeric Processor")
    num_processor = NumericProcessor()
    stream.register_processor(num_processor)

    # Il lotto di dati misti fornito dall'esempio
    datas = [
        'Hello world',
        [3.14, -1, 2.71],
        [
            {'log_level': 'WARNING', 'log_message':
             'Telnet access! Use ssh instead'},
            {'log_level': 'INFO', 'log_message': 'User wil is connected'}
        ],
        42,
        ['Hi', 'five']
    ]

    print("\nSend first batch of data on stream: "
          "['Hello world', [3.14, -1, 2.71], "
          "[{'log_level': 'WARNING', 'log_message': "
          "'Telnet access! Use ssh instead'}, "
          "{'log_level': 'INFO', 'log_message': 'User wil is connected'}],"
          " 42, ['Hi', 'five']]")
    stream.process_stream(datas)

    print()
    stream.print_processors_stats()

    print("\nRegistering other data processors")
    text_processor = TextProcessor()
    log_processor = LogProcessor()
    stream.register_processor(text_processor)
    stream
    stream.register_processor(log_processor)

    print("Send the same batch again")
    stream.process_stream(datas)

    print()
    stream.print_processors_stats()

    print("\nConsume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    # Consuma 3 elementi da Numeric
    for _ in range(3):
        num_processor.output()
    # Consuma 2 elementi da Text
    for _ in range(2):
        text_processor.output()
    # Consuma 1 elemento da Log
    log_processor.output()

    print()
    stream.print_processors_stats()

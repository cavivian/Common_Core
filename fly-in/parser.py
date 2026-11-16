# cosa devo fare:
# - try-except in cui leggo i file dei percorsi(basta farlo con sys)
# - fare il parse di tutti i file (sempre dentro il try, di quello che viene passato in input)


class Parse:
    def __init__(self, content: str) -> None:
        self.content = content

    def from_content_to_list(self, content: str) -> list:
        self.lines = content.split()
        print(f"il tipo di lines è: {type(self.lines)}")
        

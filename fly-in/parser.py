# cosa devo fare:
# - try-except in cui leggo i file dei percorsi(basta farlo con sys)
# - fare il parse di tutti i file (sempre dentro il try, di quello che
# viene passato in input)


class Parse:
    def __init__(self, content: str) -> None:
        self.content = content

    def from_content_to_list_of_dict(self, content: str) -> list:
        self.lines = content.split('\n')
        # print(self.lines)
        for i in range(len(self.lines)):
            if self.lines[i].startswith('#'):
                continue
            # cast_to_dict = dict(value.split(':') for value in content.split('\n'))
            else:
                key_dict = self.search_before_dots()
                print(key_dict)
                # cast_to_dict = dict(value.split(':') for value in self.lines[i].split('\n'))
                # print(f"il tipo di cast_to_dict e': {type(cast_to_dict)}")
                # print(f" voglio stampare il secondo elemento:'{self.lines[i]}'")
            # print(len(self.lines[i]))
        # print(f"il tipo di lines è: {type(self.lines)}")

    def search_before_dots(self) -> str:
        for i, char in enumerate(self.lines[0]):
            if char == ':':
                return self.lines[:i]
        # return self.lines

from mazegen.gest import valida, display, writeoutput, il_path
from mazegen import Maze


class MazeGenerator():
    """A class that generates a maze based on the provided configuration.
    """
    def __init__(self,
                 width: int = 20,
                 height: int = 20,
                 entry: tuple = (0, 0),
                 exit: tuple = (19, 19),
                 output_file: str = "maze.txt",
                 seed: int = 42,
                 perfect: bool = True):

        config = {
            "WIDTH": str(width),
            "HEIGHT": str(height),
            "ENTRY": str(entry).strip("()").replace(" ", ""),
            "EXIT": str(exit).strip("()").replace(" ", ""),
            "OUTPUT_FILE": output_file,
            "SEED": str(seed),
            "PERFECT": str(perfect).lower(),
        }
        self.validated = valida(config)

    def generate(self):
        width = self.validated[0]
        height = self.validated[1]
        seed = self.validated[6]
        perfect = self.validated[5]
        gen = Maze(width, height, seed, perfect)
        grid = gen.generate()
        path = il_path(grid, self.validated[2], self.validated[3])
        writeoutput(self.validated[4], grid, self.validated[2],
                    self.validated[3], path)
        display(grid, self.validated[2], self.validated[3])

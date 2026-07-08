import importlib.util
import importlib.metadata


OBBLIG = ["pandas", "numpy", "matplotlib"]
OPZ = ["requests"]


def dip(nome: str):
    cerca = importlib.util.find_spec(nome)
    if cerca is None:
        return (False, None)
    versione = importlib.metadata.version(nome)
    return (True, versione)


def grafico():
    print("Analyzing Matrix data")
    data = numpy.random.randn(1000)
    print("Processing 1000 data points...")
    graphic = pandas.DataFrame(data, columns=["Matrix_Data"])
    print("Generating visualizations...")
    matplotlib.pyplot.figure(figsize=(7, 4))
    matplotlib.pyplot.hist(graphic["Matrix_Data"], bins=30,
                           color="green", alpha=0.8, edgecolor="black")
    matplotlib.pyplot.title("Matrix Data Distribution")
    matplotlib.pyplot.xlabel("Values")
    matplotlib.pyplot.ylabel("Frequency")

    matplotlib.pyplot.savefig("matrix_analysis.png")
    matplotlib.pyplot.close()

    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")


def cntr_dip():
    print("Checking dependencies:")
    presenti = True
    frasi = {"pandas": "data manipulation ready",
             "numpy": "Numerical computation ready",
             "requests": "Network acces ready",
             "matplotlib": "visualization ready"}
    for lib in OBBLIG:
        cntr = dip(lib)
        vers = dip(lib)
        if cntr[0]:
            print(f"[OK] {lib}, ({vers[1]}) - {frasi[lib]}")
        else:
            print(f"{lib} not installed")
            presenti = False
    for lib in OPZ:
        cntr = dip(lib)
        vers = dip(lib)
        if cntr[0]:
            print(f"[OK] {lib}, ({vers[1]}) - {frasi[lib]}")
    return presenti


if __name__ == "__main__":
    print("LOADING STATUS: Loading programs...")
    verificate = cntr_dip()
    if not verificate:
        print("Missing dependencies")
        print("For pip: pip install -r requirements.txt")
        print("For Poetry: poetry install")
        print("poetry run python loading.py")
        exit()
    import pandas
    import numpy
    import matplotlib.pyplot
    grafico()

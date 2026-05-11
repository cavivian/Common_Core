import sys

def ft_inventory_system():
    args = sys.argv[1:]
    inventario = {}
    for items in args:
        divpar = items.split(':')
        if len(divpar) != 2:
           print(f"Error - invalid parameter '{items}'")
           continue
        name = divpar[0]
        value = divpar[1]
        if name in inventario:
           print(f"Redundant item '{name}' - discarding")
           continue
        try:
            quantity = int(value)
            inventario[name] = quantity
        except ValueError as e:
           print(f"Quantity error for'{name}': {e}")
    print(f"Got inventory: {inventario}")
    print(f"Item list: {list(inventario)}")
    # 1. Calcolo del totale una volta sola per evitare sprechi
    total_qty = sum(inventario.values())
    print(f"Total quantity of the {len(inventario)} items: {total_qty}")
    # 2. Inizializzazione variabili per la ricerca manuale
    max_qty = -1
    max_item = ""
    min_qty = float('inf') # Numero infinitamente grande
    min_item = ""
    # 3. Ciclo per Percentuali e Ricerca Max/Min
    for name in inventario:
        qty = inventario[name]
        
        # Calcolo percentuale corretta
        percentage = (qty / total_qty) * 100
        print(f"Item {name} represents {round(percentage, 1)}%")

        # Logica manuale per il Massimo (Most Abundant)
        if qty > max_qty:
            max_qty = qty
            max_item = name

        # Logica manuale per il Minimo (Least Abundant)
        if qty < min_qty:
            min_qty = qty
            min_item = name

    # 4. Report finale
    print(f"Item most abundant: {max_item} with quantity {max_qty}")
    print(f"Item least abundant: {min_item} with quantity {min_qty}")

    # 5. Aggiornamento e chiusura
    inventario.update({'magic_item': 1})
    print(f"Updated inventory: {inventario}")


def main() -> None:
    print("=== Inventory System Analysis ===")
    ft_inventory_system()


if __name__ == "__main__":
    main()

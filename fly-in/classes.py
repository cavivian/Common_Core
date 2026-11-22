# qui devo creare le classi per i droni, le zone e le connessioni
# capire i droni di che informazioni hanno bisogno
# capire le connessioni di che info hanno bisogno
# capire le zone di che info hanno bisogno

class Drones:
	def __init__(self, nb_drones: int):
		self.nb_drones = nb_drones
		pass


class Connections:
	def __init__(self, connections):
		self.connections = connections
		pass


class Zones:
	def __init__(self, zones):
		self.zones = zones
		pass
		
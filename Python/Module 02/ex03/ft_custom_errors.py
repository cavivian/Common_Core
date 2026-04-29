class GardenError(Exception):
	def __init__(self, message="Unknown garden error"):
		self.message = message
		super().__init__(message)

class PlantError(GardenError):
	def __init__(self, message="Unknown plant error"):
		super().__init__(message)

	def check_plant(self, temperature) ->str:
		self.temperature = temperature
		if temperature > 30:
			raise PlantError (f'The tomato plant is wilting!')

class WaterError(GardenError):
	def __init__(self, name):
		super().__init__(name)

	def check_water(self, water) ->str:
		self.water = water
		if water < 10:
			raise WaterError ('Not enough water in the tank!')



def main():
	print ('=== Custom Garden Errors Demo ===')
	print('\nTesting PlantError...')
	plant = PlantError()
	try:
		plant.check_plant(40)
	except PlantError as e:
		print(f'Caught PlantError: {e}')
	print('\nTesting WaterError...')
	idration = WaterError('Tomato')
	try:
		idration.check_water(9)
	except WaterError as e:
		print(f'Caught WaterError: {e}')
	print('\nTesting catching all gardens errors...')
	test1 = PlantError('Tomato')
	try:
		test1.check_plant(40)
	except GardenError as e:
		print(f'Caught GardenError: {e}')
	test2 = WaterError('Tomato')
	try:
		test2.check_water(9)
	except GardenError as e:
		print(f'Caught GardenError: {e}')
	print('\nAll custom error types work correctly!')

if __name__ == "__main__":
	main()
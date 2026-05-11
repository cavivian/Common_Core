class GardenError(Exception):
    def __init__(self, message="Unknown garden error"):
        self.message = message
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message="Unknown plant error"):
        super().__init__(message)

    def water_plant(self, plant_name):
        if plant_name != plant_name.capitalize():
            raise PlantError(f"Invalid plant name to water: '{plant_name}'")
        else:
            print(f'Watering {plant_name}: [OK]')

    def test_watering_system(self, plants):
        print('\nTesting valid plants...')
        print('Opening watering system')
        try:
            for plant in plants:
                self.water_plant(plant)
        except PlantError as e:
            print(f'Caught PlantError: {e}')
            print('..ending tests and returning to main')
            return
        finally:
            print('Closing watering system')


def main():
    print('=== Garden Watering System ===')
    test = PlantError()
    test.test_watering_system(['Tomato', 'Lettuce', 'Carrots'])
    test.test_watering_system(['Tomato', 'lettuce'])
    print('\nCleanup always happens, even with errors!')


if __name__ == "__main__":
    main()

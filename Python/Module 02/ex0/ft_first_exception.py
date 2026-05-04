def input_temperature(tmp_str):
	return int(tmp_str)

def test_temperature(tmp_str):
	valid = "25"
	print(f"\nInput data is '{valid}'")
	print(f"Temperature is now {input_temperature(valid)}°C")
	try:
		input_temperature('abc')
	except Exception as e:
		print(f"\nInput data is '{tmp_str}'")
		print(f'Caught input_temperature error: {e}')


def main():
	print('=== Garden Temperature ===')
	test_temperature('abc')

if __name__ == "__main__":
	main()

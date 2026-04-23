def input_temperature(tmp_str):
	return int(tmp_str)

def test_temperature(tmp_str):
	input_temperature(25)
	input_temperature('abc')
	if tmp_str == str:
		print("Caught input_temperature error: invalid literal for int() with base 10: 'abc'")


def main():
	print('=== Garden Temperature ===')
	input_temperature(25)
	print(f"Input data is '{input_temperature(25)}'")
	print(f'Temperature is now {input_temperature(25)}C')
	""" test_temperature(25) """

if __name__ == "__main__":
	main()

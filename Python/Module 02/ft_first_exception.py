def input_temperature(tmp_str):
	print('=== Garden Temperature ===')
	
	print(f"Input data is '{tmp_str}'")
	print(f"Temperature is now {tmp_str}°C")

def test_temperature(tmp_str):
	input_temperature(25)
	input_temperature('abc')
	if tmp_str == str:
		print("Caught input_temperature error: invalid literal for int() with base 10: 'abc'")


def main():
	input_temperature(25)
	test_temperature(25)

if __name__ == "__main__":
	main()

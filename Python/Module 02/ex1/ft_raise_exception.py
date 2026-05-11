def input_temperature(tmp_str):
    temp = int(tmp_str)
    if temp > 40:
        raise Exception(f"{temp}°C is too hot for plants (max 40°C)")
    if temp < 0:
        raise Exception(f"{temp}°C is too cold for plants (min 0°C)")
    return temp


def test_temperature():
    case = ["25", "abc", "100", "-50"]
    for data in case:
        print(f"\nInput data is '{data}'")
        try:
            res = input_temperature(data)
            print(f"Temperature is now {res}°C")
        except Exception as e:
            print(f"Caught input_temperature error: {e}")


def main():
    print("=== Garden Temperature Checker ===")
    test_temperature()
    print("\nAll tests completed - program didn't crash!")


if __name__ == "__main__":
    main()

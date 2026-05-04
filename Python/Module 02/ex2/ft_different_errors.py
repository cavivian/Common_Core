def garden_operations(operation_number):
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        1 / 0
    elif operation_number == 2:
        open("text.txt")
    elif operation_number == 3:
        "ciao" + 42
    elif operation_number == 4:
        return

def test_error_types():
    for i in range(5):
        print(f"Testing operation {i}...")
        try:
            garden_operations(i)
            if i == 4:
                print('Operation completed successfully!')
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught TypeError: {e}")

def main():
    print('=== Garden Error Types Demo ===')
    test_error_types()
    print("\nAll error types tested successfully!")

if __name__ == "__main__":
    main()

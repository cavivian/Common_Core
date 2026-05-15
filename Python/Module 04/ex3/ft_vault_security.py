from typing import Optional,Union, Tuple

def secure_archive(
    filename: str,                    # Obbligatorio
    action: Union[int, str] = "read", # Opzionale (scelta tra int o str)
    content: Optional[str] = None     # Opzionale (testo da scrivere)
) -> Tuple[bool, str]:
	try:
		with open(filename, "r") as f:
			print("Using 'secure_archive' to read from a nonexistent file:")
			return False
	except FileNotFoundError as e:
		print(f"False, "[Errno2]{e}: '{filename}'"")

def main():
	print('=== Cyber Archives Security ===')
	secure_archive()


if __name__ == "__main__":
	main()
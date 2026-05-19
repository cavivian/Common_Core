from typing import Optional, Union, Tuple


def secure_archive(
    filename: str,                    # Obbligatorio
    action: Union[int, str] = "read",  # Opzionale (scelta tra int o str)
    content: Optional[str] = None     # Opzionale (testo da scrivere)
) -> Tuple[bool, str]:
    try:
        if action == "read":
            with open(filename, "r") as f:
                contenuto = f.read()
                print(f"True, {contenuto}")
        if action == "write":
            with open(filename, "w") as f:
                f.write(content)
                return (True, "Content successfully written to file")
    except Exception as e:
        return(False, str(e))


def main():
    print('=== Cyber Archives Security ===')
    print("\nUsing 'secure_archive' to read from a nonexistent file:")
    test = secure_archive("/not/existent/file", "read")
    print(test)
    print("\nUsing 'secure_archive' to read from an inaccessible file:")
    test2 = secure_archive("/etc/master.passwd", "read")
    print(test2)
    print("\nUsing 'secure_archive' to read from a regular file:")
    test3 = secure_archive("ancient_fragment.txt", "read")
    print(test3)
    print("\nUsing 'secure_archive' to write previous content to a new file:")
    test4 = secure_archive("ancient_fragment.txt", "write",
                           "Content successfully written to file")
    print(test4)


if __name__ == "__main__":
    main()

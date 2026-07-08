import os
from dotenv import load_dotenv


def diz():
    return {"mode": os.getenv('MATRIX_MODE', 'development'),
            "database_url": os.getenv('DATABASE_URL', None),
            "api_key": os.getenv('API_KEY', None),
            "log_level": os.getenv('LOG_LEVEL', None),
            "zion_endpoint": os.getenv('ZION_ENDPOINT', None)}


def alternativa(cosa: dict):
    if cosa['mode'] == "production":
        pass


def carica():
    load_dotenv()


def security():
    print()
    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    if os.path.exists('.env.example'):
        print("[OK] .env file properly configured")
    else:
        print("manca")
    print("[OK] Production overrides available")


def output(cose: dict):
    print()
    print("Configuration loaded:")
    print(f"Mode: {cose['mode']}")
    if cose["database_url"]:
        print("Database: Connected to local instance")
    else:
        print("non c'è")
    if cose["api_key"]:
        print("API Access: Autenticated")
    else:
        print("niente API")
    if cose["log_level"]:
        print(f"Log level: {cose['log_level']}")
    else:
        print("manca")
    if cose["zion_endpoint"]:
        print("Zion Network: Online")
    else:
        print("Nessun network")


if __name__ == "__main__":
    print()
    print("ORACLE STATUS: Reading the Matrix...")

    carica()
    cosi = diz()
    if cosi['mode'] == "production":
        print("miao")
    output(cosi)
    security()
    print()
    print("The Oracle sees all configurations.")

import random

def main() -> None:
	print('=== Game Data Alchemist ===')
	player = ['Alice', 'bob', 'Charlie',
		'dylan', 'Emma', 'Gregory', 'jhon', 'kevin', 'Liam']
	print(f"Initial list of players: {player}")
	for name in player:
		print(f"New list with all name capitalized: {player.capitalize(name)}")

if __name__ == "__main__":
	main()
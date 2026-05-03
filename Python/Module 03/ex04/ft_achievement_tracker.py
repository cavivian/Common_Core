import random

def gen_player_achievements():
	player = {'Alice', 'Bob', 'Charlie', 'Dylan'}
	actions = {'Crafting Genius', 'Strategist', 'World Savior', 'Speed Runner',
			   'Survivor', 'Master Explorer', 'Treasure Hunter'}
	actions2 = {'Unstoppable', 'First Steps', 'Collector Supreme', 'Untouchable', 'Sharp Mind', 'Boss Slayer'}
	tot = set.union(actions, actions2)
	salvataggio = {}
	for name in player:
		num = random.randint(5, 9)
		print(f"Player {name}: {random.sample(list(tot), num)}")
		salvataggio
	print(f"\nAll distinct achievements: {tot}")
	print(f"\nCommon achievements: {salvataggio}")


def main():
	print('=== Achievement Tracker System ===')
	gen_player_achievements()

if __name__ == "__main__":
	main()
import math

def get_player_pos():
	while True:
		line = input("Enter new coordinates as floats in format 'x,y,z': ")
		try:
			part = line.split(',')
			if len(part) != 3:
				print('Invalid syntax')
				continue
			coordinata = (float(part[0].strip()), float(part[1].strip()), float(part[2].strip()))
			return coordinata
		except ValueError as e:
			for p in part:
				try:
					float(p.strip())
				except ValueError:
					print(f"Error on parameter '{p.strip()}': {e}")
					break

def main():
	print('=== Game Coordinate System ===')
	print('\nGet a first set of coordinates')
	part1 = get_player_pos()
	print(f'Got a firts tuple: ({part1})')
	print(f'It includes: X={part1[0]}, Y={part1[1]}, Z={part1[2]}')
	distance1 = math.sqrt((part1[0])**2 + (part1[1])**2 + (part1[2])**2)
	print(f'Distance to center: {round(distance1, 4)}')
	print('\nGot a second set of coordinates')
	part2 = get_player_pos()
	distance2 = math.sqrt((part2[0] - part1[0])**2 + (part2[1] - part1[1])**2 + (part2[2] - part1[2])**2)
	print(f'Distance between the 2 sets of coordinates: {round(distance2, 4)}')


if __name__ == "__main__":
	main()
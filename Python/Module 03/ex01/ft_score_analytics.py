import sys

def main():
	print('=== Player Score Analytics ===')
	i = 1
	a = sys.argv[i]
	j = len(sys.argv) - 1
	c = [int(x) for x in a]
	b = sum(c)
	if j > 1:
		for data in sys.argv[1:]:
			try:
				int(data)
			except Exception as e:
				print(f"Invalid parameter: '{data}'")
				print('No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...')
			print(f'Score processed: [{data},]')
			print(f'Total players: {j}')
			print(f'Total score: ')
			print(f'Average score: ')
			print(f'High score: {max(data)}')
			print(f'Low score: {min(data)}')
			print(f'Score range: {max(data) - min(data)}')
	else:
		print('No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...')


if __name__ == "__main__":
	main()
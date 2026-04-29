import sys

def main():
	print('=== Command Quest ===')
	i = 1
	j = len(sys.argv) - 1
	print(f'Program name: {sys.argv[0]}')
	if j == 0:
		print('No arguments provided!')
	else:
		print(f'Arguments received: {j}')
		while i < len(sys.argv):
			print(f'Argument {i}: {sys.argv[i]}')
			i += 1
	print(f'Total arguments: {len(sys.argv)}')

if __name__ == "__main__":
	main()
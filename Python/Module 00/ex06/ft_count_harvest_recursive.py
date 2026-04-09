def ft_count_harvest_recursive(day, i = 1):
	day = int(input('Days until harvest: '))
	while i <= day:
		print('Day ', i)
		i += 1
	print('Harvest time!')
	return day

	
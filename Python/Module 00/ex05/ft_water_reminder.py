day = int(input('Days since last watering: '))
if day < 2:
	print('Plants are fine')
elif day > 2:
	print('Water the plants!')
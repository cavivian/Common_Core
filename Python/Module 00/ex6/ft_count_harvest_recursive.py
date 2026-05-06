def time(day) -> None:
    i = 1
    while i <= day:
        print('Day ', i)
        i += 1

def ft_count_harvest_recursive() -> None:
    day = int(input('Days until harvest: '))
    time(day)
    print('Harvest time!')

import random
from typing import Generator


player = ['bob', 'alice', 'dylan', 'charlie']
actions = ['run', 'eat', 'sleep', 'grab', 'move', 'climb', 'swim', 'release']


def gen_event(players: list[str], actions: list[str]) -> \
        Generator[tuple[str, str], None, None]:
    while True:
        p = random.choice(players)
        a = random.choice(actions)
        yield p, a


def consume_event(event_list: list[tuple[str, str]]) -> \
        Generator[tuple[str, str], None, None]:
    while len(event_list) > 0:
        index = random.randint(0, len(event_list) - 1)
        removed = event_list.pop(index)
        yield removed


def main() -> None:
    print('=== Game Data Stream Processor ===')
    match = gen_event(player, actions)
    for i in range(1000):
        p, a = next(match)
        print(f"Event {i}: Player {p} did action {a}")
    ten_events = []
    for _ in range(10):
        ten_events.append(next(match))
    print(f"Built list of 10 events: {ten_events}")
    for event in consume_event(ten_events):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {ten_events}")


if __name__ == "__main__":
    main()

def solve():
    x, y, moves = input().split()

    x = int(x)
    y = int(y)

    dist = []
    for move in moves:
        if move == 'N':
            y = y + 1
        elif move == 'S':
            y = y - 1
        elif move == 'E':
            x = x + 1
        elif move == 'W':
            x = x - 1

        dist.append(abs(x) + abs(y))

    for t, dist in enumerate(dist, 1):
        if t >= dist:
            return str(t)

    return "IMPOSSIBLE"


T = int(input())
for case in range(1, T + 1):
    print("Case #{}: {}".format(case, solve()))

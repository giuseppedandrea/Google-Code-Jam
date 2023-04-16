def solve():
    N = int(input())
    i = 1
    acc = 0
    while True:
        m = acc + 26 * i
        if m >= N:
            return chr(((N - acc - 1) // i) + ord("A"))
        acc = m
        i += 1

if __name__ == "__main__":
    t = int(input())
    for i in range(1, t + 1):
        res = solve()
        print(f"Case #{i}: {res}")

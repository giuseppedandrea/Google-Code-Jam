def solve():
    M, R, _ = (int(s) for s in input().split(" "))
    X = [int(s) for s in input().split(' ')]
    if (X[0] - R) > 0 or (X[-1] + R) < M:
        return "IMPOSSIBLE"
    cnt = 0
    last = -R
    for i, x in enumerate(X):
        if x != X[-1] and (X[i + 1] - R) > (x + R):
            return "IMPOSSIBLE"
        if (x - R) > (last + R):
            last = X[i - 1]
            cnt += 1
    if (last + R) < M:
        cnt += 1

    return cnt

if __name__ == "__main__":
    t = int(input())
    for i in range(1, t + 1):
        res = solve()
        print(f"Case #{i}: {res}")

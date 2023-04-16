def solve():
    _ = int(input())
    S = [int(s) for s in input().split(" ")]
    res_lst = []
    res_set = set()
    last_seen = None
    for x in S:
        if x != last_seen:
            res_lst.append(x)
            res_set.add(x)
        last_seen = x
    if len(res_set) != len(res_lst):
        return "IMPOSSIBLE"

    return " ".join(str(x) for x in res_lst)

if __name__ == "__main__":
    t = int(input())
    for i in range(1, t + 1):
        res = solve()
        print(f"Case #{i}: {res}")

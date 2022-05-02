def solve():
    U = int(input())

    all_letters = []

    D = {}
    for i in range(10000):
        Q, R = input().split()
        for r in R:
            if r not in all_letters:
                all_letters.append(r)
        if R[0] not in D:
            D[R[0]] = 1
        else:
            D[R[0]] += 1

    sol = ""
    for l in all_letters:
        if l not in D:
            sol = l

    sol += "".join([k for k, v in sorted(D.items(), key=lambda item: item[1], reverse=True)])

    return sol


T = int(input())
for case in range(1, T + 1):
    print("Case #{}: {}".format(case, solve()))

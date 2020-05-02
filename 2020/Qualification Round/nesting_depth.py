def solve(s):
    s_ = ""
    open = 0
    for d in s:
        if open > int(d):
            s_ += ")" * (open - int(d))
            open -= (open - int(d))
        if open < int(d):
            s_ += "(" * (int(d) - open)
            open += (int(d) - open)
        s_ += d
    s_ += ")" * open

    return s_


T = int(input())
for case in range(1, T + 1):
    s = input()

    print("Case #{}: {}".format(case, solve(s)))

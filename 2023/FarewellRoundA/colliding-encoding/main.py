def solve():
    D = input().split(" ")
    N = int(input())
    E = set()
    for _ in range(N):
        S = input()
        e = ""
        for letter in S:
            e += D[ord(letter) - ord("A")]
        E.add(e)
    
    return "YES" if len(E) != N else "NO"

if __name__ == "__main__":
    t = int(input())
    for i in range(1, t + 1):
        res = solve()
        print(f"Case #{i}: {res}")

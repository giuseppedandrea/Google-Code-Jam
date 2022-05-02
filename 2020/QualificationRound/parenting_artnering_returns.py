def solve(activities):
    schedule = []

    activities.sort(key=lambda x: x[0])

    C_end = 0
    J_end = 0
    for activity in activities:
        activity_start = activity[0]
        activity_end = activity[1]
        position = activity[2]

        if C_end <= activity_start:
            C_end = activity_end
            schedule.append([position, "C"])
            continue
        if J_end <= activity_start:
            J_end = activity_end
            schedule.append([position, "J"])
            continue

        return "IMPOSSIBLE"

    schedule.sort(key=lambda x: x[0])

    return ''.join([x[1] for x in schedule])


T = int(input())
for case in range(1, T + 1):
    N = int(input())
    activities = []
    for i in range(N):
        activity = list(map(int, input().split()))
        activity.append(i)
        activities.append(activity)

    print("Case #{}: {}".format(case, solve(activities)))

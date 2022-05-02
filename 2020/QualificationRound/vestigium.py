def solve(matrix, N):
    matrix_by_rows = matrix
    matrix_by_columns = []

    for i in range(N):
        matrix_by_columns.append([row[i] for row in matrix_by_rows])

    trace = 0
    n_rows_repeated = 0
    for i, row in enumerate(matrix_by_rows):
        trace += row[i]
        if len(row) != len(set(row)):
            n_rows_repeated += 1

    n_columns_repeated = 0
    for column in matrix_by_columns:
        if len(column) != len(set(column)):
            n_columns_repeated += 1

    return "{} {} {}".format(trace, n_rows_repeated, n_columns_repeated)


T = int(input())
for case in range(1, T + 1):
    N = int(input())
    matrix = []
    for i in range(N):
        matrix.append(list(map(int, input().split())))

    print("Case #{}: {}".format(case, solve(matrix, N)))

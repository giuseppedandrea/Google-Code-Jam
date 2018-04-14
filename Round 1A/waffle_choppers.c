/*
# Problem

The diners at the Infinite House of Pancakes have gotten tired of circular pancakes, so the chefs are about to offer a new menu option: waffles! As a publicity stunt, they have made one large waffle that is a grid of square cells with R rows and C columns. Each cell of the waffle is either empty, or contains a single chocolate chip.

Now it is time for the chefs to divide up the waffle among their hungry diners. A horizontal cut runs along the entire gridline between two of the rows; a vertical cut runs along the entire gridline between two of the columns. For efficiency's sake, one chef will make exactly H different horizontal cuts and another chef will make exactly V different vertical cuts. This will conveniently create one piece for each of the (H + 1) × (V + 1) diners. The pieces will not necessarily all be of equal sizes, but that is fine; market research has shown that the diners do not care about that.

What the diners do care about is the number of chocolate chips they get, so each piece must have exactly the same number of chocolate chips. Can you determine whether the chefs can accomplish this goal using the given numbers of horizontal and vertical cuts?

# Input

The first line of the input gives the number of test cases, T; T test cases follow. Each begins with one line containing four integers R, C, H, and V: the number of rows and columns in the waffle, and the exact numbers of horizontal and vertical cuts that the chefs must make. Then, there are R more lines of C characters each; the j-th character in the i-th of these lines represents the cell in the i-th row and the j-th column of the waffle. Each character is either @, which means the cell has a chocolate chip, or ., which means the cell is empty.

# Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is POSSIBLE if the chefs can accomplish the goal as described above, or IMPOSSIBLE if they cannot.

# Limits

1 ≤ T ≤ 100.
Time limit: 6 seconds per test set.
Memory limit: 1GB.

# Test set 1 (Visible)

2 ≤ R ≤ 10.
2 ≤ C ≤ 10.
H = 1.
V = 1.

# Test set 2 (Hidden)

2 ≤ R ≤ 100.
2 ≤ C ≤ 100.
1 ≤ H < R.
1 ≤ V < C.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int T, R, C, H, V;
    char buffer;
    int matrix[100][100];
    int sum_row[100], sum_column[100], cut_row[99], cut_column[99], cut_inc, cut_sum, cut_n, next_test;

    scanf(" %d", &T);

    for (size_t Ti = 0; Ti < T; Ti++) {
        scanf(" %d%d%d%d", &R, &C, &H, &V);

        for (size_t i = 0; i < R; i++) {
            (i==0) ? (sum_row[i]=0) : (sum_row[i]=sum_row[i-1]);

            for (size_t j = 0; j < C; j++) {
                if (i==0) {
                    sum_column[j]=0;
                }
                if (i==(R-1) && j>0) {
                    sum_column[j]+=sum_column[j-1];
                }

                scanf(" %c", &buffer);
                if (buffer=='@') {
                    sum_row[i]++;
                    sum_column[j]++;
                    matrix[i][j]=1;
                } else {
                    matrix[i][j]=0;
                }
            }
        }

        next_test=0;

        if (sum_row[R-1]==0) {
            printf("Case %d: POSSIBLE\n", Ti+1);
            continue;
        }

        if (sum_row[R-1]%(H+1)) {
            printf("Case %d: IMPOSSIBLE\n", Ti+1);
            continue;
        }
        cut_inc=sum_row[R-1]/(H+1);
        cut_sum=cut_inc;
        cut_n=0;
        for (size_t i = 0; i < (R-1); i++) {
            if (sum_row[i]==cut_sum) {
                cut_row[cut_n++]=i;
                cut_sum+=cut_inc;
            }
        }
        if (cut_n!=H) {
            printf("Case %d: IMPOSSIBLE\n", Ti+1);
            continue;
        }

        if (sum_column[C-1]%(V+1)) {
            printf("Case %d: IMPOSSIBLE\n", Ti+1);
            continue;
        }
        cut_inc=sum_column[C-1]/(V+1);
        cut_sum=cut_inc;
        cut_n=0;
        for (size_t i = 0; i < (C-1); i++) {
            if (sum_column[i]==cut_sum) {
                cut_column[cut_n++]=i;
                cut_sum+=cut_inc;
            }
        }
        if (cut_n!=V) {
            printf("Case %d: IMPOSSIBLE\n", Ti+1);
            continue;
        }

        cut_inc=sum_column[C-1]/((H+1)*(V+1));
        for (size_t i = 0; i < (H+1) && !next_test; i++) {
            size_t i_start=((i==0) ? (0) : (cut_row[i-1]+1));
            size_t i_end=((i==H) ? (R-1) : (cut_row[i]));
            for (size_t j = 0; j < (V+1) && !next_test; j++) {
                size_t j_start=((j==0) ? (0) : (cut_column[j-1]+1));
                size_t j_end=((j==V) ? (C-1) : (cut_column[j]));
                cut_sum=0;
                for (size_t _i = i_start; _i <= i_end; _i++) {
                    for (size_t _j = j_start; _j <= j_end; _j++) {
                        cut_sum+=matrix[_i][_j];
                    }
                }
                if (cut_sum!=cut_inc) {
                    printf("Case %d: IMPOSSIBLE\n", Ti+1);
                    next_test=1;
                }
            }
        }

        if (!next_test) {
            printf("Case %d: POSSIBLE\n", Ti+1);
        }
    }

    return 0;
}

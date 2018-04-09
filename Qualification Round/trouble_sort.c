/*
# Problem

Deep in Code Jam's secret algorithm labs, we devote countless hours to wrestling with one of the most complex problems of our time: efficiently sorting a list of integers into non-decreasing order. We have taken a careful look at the classic bubble sort algorithm, and we are pleased to announce a new variant.

The basic operation of the standard bubble sort algorithm is to examine a pair of adjacent numbers, and reverse that pair if the left number is larger than the right number. But our algorithm examines a group of three adjacent numbers, and if the leftmost number is larger than the rightmost number, it reverses that entire group. Because our algorithm is a "triplet bubble sort", we have named it Trouble Sort for short.

  TroubleSort(L): // L is a 0-indexed list of integers
    let done := false
    while not done:
      done = true
      for i := 0; i < len(L)-2; i++:
        if L[i] > L[i+2]:
          done = false
          reverse the sublist from L[i] to L[i+2], inclusive

For example, for L = 5 6 6 4 3, Trouble Sort would proceed as follows:
- First pass:
-- inspect 5 6 6, do nothing: 5 6 6 4 3
-- inspect 6 6 4, see that 6 > 4, reverse the triplet: 5 4 6 6 3
-- inspect 6 6 3, see that 6 > 3, reverse the triplet: 5 4 3 6 6
- Second pass:
-- inspect 5 4 3, see that 5 > 3, reverse the triplet: 3 4 5 6 6
-- inspect 4 5 6, do nothing: 3 4 5 6 6
-- inspect 5 6 6, do nothing: 3 4 5 6 6
- Then the third pass inspects the three triplets and does nothing, so the algorithm terminates.

We were looking forward to presenting Trouble Sort at the Special Interest Group in Sorting conference in Hawaii, but one of our interns has just pointed out a problem: it is possible that Trouble Sort does not correctly sort the list! Consider the list 8 9 7, for example.

We need your help with some further research. Given a list of N integers, determine whether Trouble Sort will successfully sort the list into non-decreasing order. If it will not, find the index (counting starting from 0) of the first sorting error after the algorithm has finished: that is, the first value that is larger than the value that comes directly after it when the algorithm is done.

# Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of two lines: one line with an integer N, the number of values in the list, and then another line with N integers Vi, the list of values.

# Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is OK if Trouble Sort correctly sorts the list, or the index (counting starting from 0) of the first sorting error, as described above.

# Limits

1 ≤ T ≤ 100.
0 ≤ Vi ≤ 109, for all i.
Memory limit: 1GB.

# Test set 1 (Visible)

3 ≤ N ≤ 100.
Time limit (for the entire test set): 10 seconds.

# Test set 2 (Hidden)

3 ≤ N ≤ 105.
Time limit (for the entire test set): 20 seconds.

# Special Note

Notice that test set 2 for this problem has a large amount of input, so using a non-buffered reader might lead to slower input reading. In addition, keep in mind that certain languages have a small input buffer size by default.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
   return(*(long*)a-*(long*)b);
}

int main(int argc, char const *argv[]) {
  int T, next_test;
  long N, N1, N2;
  long *V1, *V2;

  scanf("%d\n", &T);

  for (size_t i = 0; i < T; i++) {
    scanf("%li\n", &N);
    N1=(N&1 ? ((N/2)+1) : (N/2));
    N2=N/2;
    V1=(long *)calloc(N1 ,sizeof(*V1));
    V2=(long *)calloc(N2 ,sizeof(*V2));
    for (size_t j = 0; j < N; j++) {
      if (j&1) {
        scanf("%li", &V2[(j-1)>>1]);
      } else {
        scanf("%li", &V1[j>>1]);
      }
    }
    qsort(V1, N1, sizeof(long), cmp);
    qsort(V2, N2, sizeof(long), cmp);
    next_test=0;
    for (long j = 1; j < N; j++) {
      if (j&1) {
        if (V2[(j-1)>>1]<V1[(j-1)>>1]) {
          printf("Case #%d: %li\n", i+1, j-1);
          next_test=1;
          break;
        }
      } else {
        if (V1[(j>>1)]<V2[(j>>1)-1]) {
          printf("Case #%d: %li\n", i+1, j-1);
          next_test=1;
          break;
        }
      }
    }
    if (!next_test) {
      printf("Case #%d: OK\n", i+1);
    }
  }

  return 0;
}

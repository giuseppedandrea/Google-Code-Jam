#include <bits/stdc++.h>

using namespace std;

void rsolve() {
    int l[100];
    int n;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l[i];
    }

    int c = 0;
    for (int i = 0; i < (n - 1); i++) {
        int pos = i;
        while (l[pos] != (i + 1)) {
            pos++;
        }
        c += pos - i + 1;
        for (int j = 0; j < ((pos - i + 1) / 2); j++) {
            swap(l[j + i], l[pos - j]);
        }
    }

    cout << c << endl;

    return;
}

void solve() {
    int t;
    cin >> t;
    for(int casenum = 1; casenum <= t; casenum++) {
        cout << "Case #" << casenum << ": ";
        rsolve();
    }

    return;
}

int main() {
    solve();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void rsolve() {
    int l[100];
    int n, c;
    cin >> n;
    cin >> c;

    if (c < (n - 1) || c > ((((n + 1) * n) - 1) / 2)) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int c_ = 0;
    int changes = 0;
    int idx_l = 0;
    int idx_r = n - 1;
    for (int i = 0; i < (n - 1); i++) {
        if (((n - i) + (n - i - 2) + c_) <= c) {
            if ((changes % 2) == 0) {
                l[idx_r--] = i + 1;
            } else {
                l[idx_l++] = i + 1;
            }
            c_ += n - i;
            changes++;
        } else {
            if ((changes % 2) == 0) {
                l[idx_l++] = i + 1;
            } else {
                l[idx_r--] = i + 1;
            }
            c_ += 1;
        }
    }

    l[idx_l] = n;

    for (int i = 0; i < (n); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << l[i];
    }
    cout << endl;

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

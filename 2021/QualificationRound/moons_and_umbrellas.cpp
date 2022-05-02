#include <bits/stdc++.h>

using namespace std;

void rsolve() {
    int x, y;
    string  s;

    cin >> x;
    cin >> y;
    cin >> s;

    int i = 0;
    int cnt;
    while (i < s.length()) {
        cnt = 1;
        if (s[i] == '?') {
            while ((i + cnt) < s.length() && s[i + cnt] == '?') {
                cnt++;
            }
            for (int j = 0; j < cnt; j++) {
                if (x > 0 && y > 0) {
                    if (cnt == s.length()) {
                        s[j + i] = 'C';
                    } else if (i == 0) {
                        s[j + i] = s[i + cnt];
                    } else {
                        s[j + i] = s[i - 1];
                    }
                } else {
                    // TODO Extra credit
                }
            }
        }
        i += cnt;
    }

    int c = 0;
    for (int i = 0; i < (s.length() - 1); i++) {
        if (s[i] == 'C' && s[i + 1] == 'J') {
            c += x;
        }
        if (s[i] == 'J' && s[i + 1] == 'C') {
            c += y;
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

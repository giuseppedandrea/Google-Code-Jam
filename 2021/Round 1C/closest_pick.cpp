#include <bits/stdc++.h>

using namespace std;

void rsolve() {
    int n, k;
    vector<int> v;

    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));

    vector<int> dist;
    for (auto i = v.begin(); i != v.end() - 1; ++i) {
        int l = *i;
        int r = *(i + 1);
        dist.push_back((r - l) / 2);
        dist.push_back((r - l - 1) - (r - l) / 2);
    }
    dist.push_back(v.front() - 1);
    dist.push_back(k - v.back());

    sort(dist.begin(), dist.end());
    double prob = (*(dist.end() - 1) + *(dist.end() - 2)) / (double)k;
    cout << fixed << setprecision (9) << prob << endl;

    return;
}

void solve() {
    int t;
    cin >> t;
    for (int casenum = 1; casenum <= t; casenum++) {
        cout << "Case #" << casenum << ": ";
        rsolve();
    }

    return;
}

int main() {
    solve();

    return 0;
}

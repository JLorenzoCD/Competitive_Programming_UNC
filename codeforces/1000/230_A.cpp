// https://codeforces.com/contest/230/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull s, n;
    cin >> s >> n;

    vector<pair<ull, ull>> v(n);
    for (pair<ull, ull> &e : v) {
        cin >> e.first >> e.second;
    }

    sort(v.begin(), v.end());

    bool is_loss = false;
    for (ull i = 0u; i < n && !is_loss; i++) {
        if (v[i].first < s) {
            s += v[i].second;
        }
        else {
            is_loss = true;
        }
    }

    cout << (is_loss ? "NO" : "YES") << endl;

    return EXIT_SUCCESS;
}
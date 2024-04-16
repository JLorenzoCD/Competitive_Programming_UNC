// https://codeforces.com/contest/903/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n;
    cin >> n;

    map<ull, ull> mp;

    ull a;
    for (ull i = 0; i < n; i++) {
        cin >> a;

        if (mp.count(a)) {
            mp[a] += 1u;
        }
        else {
            mp[a] = 1u;
        }
    }

    ull m = 0u;
    for (auto [k, v] : mp) {
        m = max(m, v);
    }

    cout << m << endl;

    return EXIT_SUCCESS;
}
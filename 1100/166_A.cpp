// https://codeforces.com/contest/166/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n, k;
    cin >> n >> k;

    map<unsigned int, unsigned int> m;

    unsigned int p, t;
    for (unsigned int i = 0; i < n; i++) {
        cin >> p >> t;

        unsigned int score = p * 1000 - t;
        if (m.count(score)) {
            m[score] += 1u;
        }
        else {
            m[score] = 1u;
        }
    }

    unsigned int pos = 0u;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        // cout << it->first << " " << it->second << endl;
        pos += it->second;

        if (k <= pos) {
            cout << it->second << endl;
            break;
        }
    }

    return EXIT_SUCCESS;
}
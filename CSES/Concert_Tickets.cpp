// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n, m;
    cin >> n >> m;

    vector<ull> h(n);
    for (ull&e : h) { // O( n )
        cin >> e;
    }
    vector<ull> t(m);
    for (ull&e : t) { // O( m )
        cin >> e;
    }

    sort(h.begin(), h.end()); // O( n*Log(n) )

    ull index_max;
    for (ull i = 0; i < m; i++) { // O( m )
        index_max = lower_bound(h.begin(), h.end(), t[i]) - h.begin(); // O( Log(n) ) => O( m*Log(n) )


        if (t[i] == h[index_max]) {
            cout << h[index_max] << endl;
            h.erase(h.begin() + index_max);
        }
        else if (index_max == 0u) {
            cout << -1 << endl;
        }
        else {
            cout << h[index_max - 1u] << endl;
            h.erase(h.begin() + index_max - 1u);
        }
    }

    return EXIT_SUCCESS;
}
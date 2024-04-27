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
    set<pair<ull, ull>> st;
    for (ull i = 0; i < n; i++) {
        cin >> h[i];
        st.insert({ h[i], i });
    }

    vector<ull> t(m);
    for (ull&e : t) {
        cin >> e;
    }

    sort(h.begin(), h.end());

    for (ull i = 0; i < m; i++) {
        auto match = st.lower_bound({ t[i] + 1u, 0 });

        if (match == st.begin()) {
            cout << -1 << endl;
        }
        else {
            --match;
            cout << match->first << endl;
            st.erase(match);
        }
    }

    return EXIT_SUCCESS;
}

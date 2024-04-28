// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool comp(pair<ull, ull> el1, pair<ull, ull> el2) {
    return el1.first <= el2.first;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n, x;
    cin >> n >> x;

    vector<pair<ull, ull>> a(n);
    ull el;
    for (ull i = 0; i < n; i++) {
        cin >> el;

        // Quiero ordenar los elmentos y poder obtener los indeices de estos cuando estaban desordenados
        a[i].first = el;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    pair<ull, ull> res = { 0u, 0u };
    ull l, r;
    l = 0u;
    r = n - 1u;
    while (l < r && res.first == 0u && res.second == 0u) {
        if (x < a[l].first + a[r].first) {
            r--;
        }
        else if (a[l].first + a[r].first < x) {
            l++;
        }
        else if (a[l].first + a[r].first == x) {
            res.first = a[l].second;
            res.second = a[r].second;
        }
    }

    if (res.first == 0u && res.second == 0u) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        res.first++;
        res.second++;

        cout << (res.first) << " " << (res.second) << endl;
    }

    return EXIT_SUCCESS;
}

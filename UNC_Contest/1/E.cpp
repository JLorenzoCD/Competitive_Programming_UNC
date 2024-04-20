// https://codeforces.com/group/gmV7IkT2pN/contest/516385/problem/E

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef struct {
    ull n;
    ull q;
    vector<ull> a;
    vector<pair<ull, pair<ull, ull>>> v;
} TestCase;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull t;
    cin >> t;

    vector<TestCase> d(t);
    for (ull i = 0; i < t; i++) {
        TestCase *temp = &d[i];

        cin >> temp->n >> temp->q;

        ull e;
        for (ull j = 0; j < temp->n; j++) {
            cin >> e;
            temp->a.push_back(e);
        }

        for (ull j = 1; j < temp->n; j++) {
            temp->a[j] += temp->a[j - 1u];
        }

        for (ull j = 0; j < temp->q; j++) {
            // l, r, k
            pair<ull, pair<ull, ull>> el;

            cin >> el.first >> el.second.first >> el.second.second;
            temp->v.push_back(el);
        }
    }

    for (ull i = 0; i < t; i++) {
        TestCase *temp = &d[i];

        ull n = temp->n;
        for (ull j = 0; j < temp->q; j++) {
            ull l = temp->v[j].first;
            ull r = temp->v[j].second.first;
            ull k = temp->v[j].second.second;

            ull w = r - l + 1u;

            ull sum_t = temp->a[n - 1u];
            ull sum_r = temp->a[r - 1u];
            ull sum_l = l == 1u ? 0u : temp->a[l - 2u];

            ull sum = sum_t - sum_r + sum_l + (w * k);

            cout << (sum % 2 == 1 ? "YES" : "NO") << endl;
        }

    }

    return EXIT_SUCCESS;
}
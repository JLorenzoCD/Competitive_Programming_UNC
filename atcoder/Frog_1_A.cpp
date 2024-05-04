// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void f(vector<unsigned int> *h, vector<unsigned int> *dp, unsigned int n, ull i) {
    if ((*dp)[i] != 0u) return;

    if (i == n - 1u) {
        (*dp)[i] = 0u;
    }
    else if (i == n - 2u) {
        int d = (*h)[i] - (*h)[i + 1u];

        (*dp)[i] = abs(d);
    }
    else {
        f(h, dp, n, i + 1u);
        f(h, dp, n, i + 2u);

        int d1 = (*h)[i] - (*h)[i + 1u];
        int d2 = (*h)[i] - (*h)[i + 2u];

        (*dp)[i] = min(
            abs(d1) + (*dp)[i + 1u],
            abs(d2) + (*dp)[i + 2u]
        );
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n;
    cin >> n;

    vector<unsigned int> h(n);
    for (unsigned int& e : h) {
        cin >> e;
    }

    vector<unsigned int> dp(n);

    f(&h, &dp, n, 0u);

    cout << dp[0u] << endl;

    return EXIT_SUCCESS;
}
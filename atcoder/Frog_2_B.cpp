// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void f(vector<unsigned int>* h, vector<unsigned int>* dp, unsigned int n, unsigned int k, unsigned int i) {
    if ((*dp)[i] != 0u) return;

    if (i == n - 1u) {
        (*dp)[i] = 0u;
    }
    else if (i == n - 2u) {
        int d = (*h)[i] - (*h)[i + 1u];

        (*dp)[i] = abs(d);
    }
    else {
        (*dp)[i] = numeric_limits<unsigned int>::max();

        for (unsigned int j = 0; j <= k; j++) {
            unsigned int jump = i + j;

            if (n <= jump) break;

            f(h, dp, n, k, jump);

            int d = (*h)[i] - (*h)[jump];
            unsigned int jump_cost = abs(d) + (*dp)[jump];

            (*dp)[i] = min((*dp)[i], jump_cost);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n, k;
    cin >> n >> k;

    vector<unsigned int> h(n);
    for (unsigned int& el : h) {
        cin >> el;
    }

    vector<unsigned int> dp(n);

    f(&h, &dp, n, k, 0u);

    cout << dp[0u] << endl;

    return EXIT_SUCCESS;
}
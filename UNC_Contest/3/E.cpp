// https://codeforces.com/group/gmV7IkT2pN/contest/522472/problem/E

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef unsigned int uint;

const unsigned int MOD = 1e9 + 7;

ull d(ull x, ull rest) {
    return (x + ((3 - rest) % 3)) / 3;
}

ull f(ull x, ull rest, vector<vector<ll>> &dp, ull cof[3u]) {
    if (x == 0u) {
        return rest == 0u ? 1u : 0u;
    }

    if (dp[x][rest] != -1) return dp[x][rest];

    dp[x][rest] = 0u;
    for (uint i = 0; i < 3; i++) {
        dp[x][rest] += (ull)cof[i] * f(x - 1, (rest + i) % 3, dp, cof);
        dp[x][rest] = dp[x][rest] % MOD;
    }

    return dp[x][rest];
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n, l, r;
    cin >> n >> l >> r;

    ull cof[3u];
    cof[0u] = d(r, 0u) - d(l - 1u, 0u);
    cof[1u] = d(r, 1u) - d(l - 1u, 1u);
    cof[2u] = d(r, 2u) - d(l - 1u, 2u);

    vector<vector<ll>> dp(n + 1, vector<ll>(3u, -1));

    cout << f(n, 0u, dp, cof) << endl;

    return EXIT_SUCCESS;
}
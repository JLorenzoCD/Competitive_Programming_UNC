// https://codeforces.com/group/gmV7IkT2pN/contest/522472/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef unsigned int uint;



ull f(vector<vector<ull>>& H_ROW, vector<vector<ll>>& dp, ull x, ull y) {
    if (x == 0) return H_ROW[y][x];

    if (dp[y][x] != -1) return dp[y][x];

    ull op1 = f(H_ROW, dp, x - 1, y);
    ull op2 = f(H_ROW, dp, x - 1, (y + 1) % 2);

    dp[y][x] = max(op1, op2 + H_ROW[y][x]);

    return dp[y][x];
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull N;
    cin >> N;

    vector<vector<ull>> H_ROW(2u, vector<ull>(N));
    for (ull&el : H_ROW[0u]) {
        cin >> el;
    }
    for (ull&el : H_ROW[1u]) {
        cin >> el;
    }

    vector<vector<ll>> dp(2u, vector<ll>(N, -1));

    ull op1 = f(H_ROW, dp, N - 1, 0u);
    ull op2 = f(H_ROW, dp, N - 1, 1u);

    cout << max(op1, op2) << endl;

    return EXIT_SUCCESS;
}
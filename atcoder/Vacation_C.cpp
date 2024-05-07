// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void f(vector<array< uint, 3u>> *v, vector<array< uint, 3u>> *dp, uint n, uint i, uint act) {
    if ((*dp)[i][act] != 0u) return;

    if (i + 1u == n) {
        (*dp)[i][act] = (*v)[i][act];
    }
    else {
        uint act_1 = ((act + 1u) % 3);
        uint act_2 = ((act + 2u) % 3);

        f(v, dp, n, i + 1u, act_1);
        f(v, dp, n, i + 1u, act_2);

        uint points_acum_1 = (*dp)[i + 1u][act_1];
        uint points_acum_2 = (*dp)[i + 1u][act_2];

        uint points_actual_act = (*v)[i][act];

        (*dp)[i][act] = max(points_acum_1 + points_actual_act, points_acum_2 + points_actual_act);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint n;
    cin >> n;

    vector<array< uint, 3u>> v(n);
    for (uint i = 0; i < n; i++) {
        cin >> v[i][0u] >> v[i][1u] >> v[i][2u];
    }

    vector<array< uint, 3u>> dp(n);

    f(&v, &dp, n, 0u, 0u);
    f(&v, &dp, n, 0u, 1u);
    f(&v, &dp, n, 0u, 2u);

    cout << (max(max(dp[0u][0u], dp[0u][1u]), dp[0u][2u])) << endl;

    return EXIT_SUCCESS;
}

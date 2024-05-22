// https://codeforces.com/group/gmV7IkT2pN/contest/525522/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

void dfs(uint v, vector<vector<uint>> &g, vector<bool> &vis, vector<ull> &cost, pair<uint, ull> &min_gold) {
    vis[v] = true;

    if (cost[v] < min_gold.second) {
        min_gold.first = v;
        min_gold.second = cost[v];
    }

    for (ll u : g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis, cost, min_gold);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N, M;
    cin >> N >> M;

    vector<bool> vis(N, false);

    vector<ull> cost(N);
    for (ull &gold : cost) {
        cin >> gold;
    }

    vector<vector<uint>> g(N);
    for (uint i = 0; i < M; i++) {
        uint u, v;
        cin >> u >> v;

        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<pair<uint, ull>> inicio_menor_costo;

    for (uint i = 0; i < N; i++) {
        if (!vis[i]) {
            pair<uint, ull> min_gold = make_pair(0u, LONG_LONG_MAX);
            dfs(i, g, vis, cost, min_gold);
            inicio_menor_costo.push_back(min_gold);
        }
    }

    ull sum = 0u;
    for (auto el : inicio_menor_costo) {
        sum += el.second;
    }

    cout << sum << endl;

    return EXIT_SUCCESS;
}
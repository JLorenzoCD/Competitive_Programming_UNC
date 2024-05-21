// https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

void dfs(uint v, vector<vector<uint>> &g, vector<bool> &vis) {
    vis[v] = true;

    for (ll u : g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N, M;
    cin >> N >> M;

    vector<bool> vis(N, false);
    vector<vector<uint>> g(N);
    for (uint i = 0; i < M; i++) {
        uint u, v;
        cin >> u >> v;

        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<uint> comienzo_grafo;

    for (uint i = 0; i < N; i++) {
        if (!vis[i]) {
            comienzo_grafo.push_back(i);
            dfs(i, g, vis);
        }
    }

    cout << comienzo_grafo.size() - 1 << endl;
    if (1 < comienzo_grafo.size()) {
        uint curr, prev = comienzo_grafo[0u];
        for (size_t i = 1u; i < comienzo_grafo.size(); i++) {
            curr = comienzo_grafo[i];

            cout << curr + 1u << " " << prev + 1u << endl;
            prev = curr;
        }
    }


    return EXIT_SUCCESS;
}
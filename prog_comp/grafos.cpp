#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

void dfs(ll v, vector<vector<ll>> &g, vector<bool> &vis) {
    vis[v] = true;

    for (ll u : g[v]) {
        if (!vis[u]) {
            dfs(u, g, vis);
        }
    }
}

void bfs(ll v, vector<vector<ll>> &g) {
    vector<bool> vis((ll)(g.size()));
    queue<ll> q;

    vis[v] = true;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (ll u : g[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // Leer grafos
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    vector<bool> vis(m, false);

    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;

        u--; v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Llamar a bfs o dfs
    bfs(0u, g);
    dfs(0u, g, vis);

    return EXIT_SUCCESS;
}
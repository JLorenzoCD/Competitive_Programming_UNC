// https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;


bool bfs(uint v, vector<vector<uint>> &g, vector<uint> &path) {
    vector<bool> vis((uint)(g.size()));
    queue<uint> q;

    vis[v] = true;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        if (v == g.size() - 1) return true;

        for (ll u : g[v]) {


            if (!vis[u]) {
                vis[u] = true;
                q.push(u);

                path[u] = v;
            }
        }
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint n, m;
    cin >> n >> m;
    vector<vector<uint>> g(n);

    for (uint i = 0u; i < m; i++) {
        uint u, v;
        cin >> u >> v;

        u--; v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<uint> path(n);
    if (bfs(0u, g, path)) {

        uint v = n - 1;
        deque<uint> res_path;
        while (v != 0u) {
            res_path.push_back(v);
            v = path[v];
        }
        res_path.push_back(0u);

        cout << res_path.size() << endl;
        while (!res_path.empty()) {
            cout << (res_path.back() + 1u) << " ";
            res_path.pop_back();
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
    cout << endl;

    return EXIT_SUCCESS;
}
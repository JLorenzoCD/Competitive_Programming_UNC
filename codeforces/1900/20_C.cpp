// https://codeforces.com/contest/20/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

uint mini_dist(vector<uint> &distance, vector<bool> &vis, uint v_start) {
    uint minimum = numeric_limits<uint>::max();
    uint ind = v_start;

    for (uint i = 0; i < vis.size(); i++) {
        if (!vis[i] && distance[i] < minimum) {
            minimum = distance[i];
            ind = i;
        }
    }

    return ind;
}

vector<uint> dijkstra(uint v_start, vector<vector<uint>> &graph, vector<bool> &vis) {
    uint N = graph.size();

    vector<uint> distance(N, numeric_limits<uint>::max());

    // Actualizando distancia a si mismo a 0
    distance[v_start] = 0;

    vector<uint> path(N);

    for (uint i = 0; i < N; i++) {
        uint m = mini_dist(distance, vis, v_start);

        if (vis[m] && m == v_start) {
            continue;
        }

        vis[m] = true;
        for (uint j = 0; j < N; j++) {
            // Actualizando la distancia de los vortices cercanos
            if (!vis[j] && graph[m][j] != numeric_limits<uint>::max() && distance[m] != numeric_limits<uint>::max() && distance[m] + graph[m][j] < distance[j]) {
                distance[j] = distance[m] + graph[m][j];
                path[j] = m + 1u;
            }
        }
    }

    return path;
}


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N, M;
    cin >> N >> M;

    vector<vector<uint>> g(N, vector<uint>(N, numeric_limits<uint>::max()));
    for (uint i = 0; i < M; i++) {
        uint a, b, w;
        cin >> a >> b >> w;

        --a;
        --b;
        g[a][b] = w;
        g[b][a] = w;
    }

    vector<bool> vis(N, false);

    vector<uint> path = dijkstra(0u, g, vis);

    stack<uint> res;
    res.push(N);

    bool ok = true;
    uint sig = path[N - 1];
    while (ok) {
        res.push(sig);

        if (sig == 0) { ok = false; break; }
        if (sig == 1u) break;

        sig = path[sig - 1];
    }

    if (!ok) {
        cout << -1;
    }
    else {
        while (!res.empty()) {
            cout << res.top() << " ";
            res.pop();
        }
    }
    cout << endl;

    return EXIT_SUCCESS;
}
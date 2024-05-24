#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

uint mini_dist(vector<uint> &path, vector<bool> &vis) {
    uint minimum = INT_MAX, ind;

    for (uint i = 0; i < vis.size(); i++) {
        if (!vis[i] && path[i] <= minimum) {
            minimum = path[i];
            ind = i;
        }
    }

    return ind;
}

vector<uint> dijkstra(uint v_start, vector<vector<uint>> &graph, vector<bool> &vis) {
    uint N = graph.size();

    vector<uint> distance(N, INT_MAX);

    // Actualizando distancia a si mismo a 0
    distance[v_start] = 0;

    for (uint i = 0; i < N; i++) {
        uint m = mini_dist(distance, vis);
        vis[m] = true;

        for (uint j = 0; j < N; j++) {
            // Actualizando la distancia de los vortices cercanos
            if (!vis[j] && graph[m][j] && distance[m] != INT_MAX && distance[m] + graph[m][j] < distance[j]) {
                distance[j] = distance[m] + graph[m][j];
            }
        }
    }

    return distance;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll N, M;
    cin >> N >> M;

    // Dijkstra
    vector<vector<uint>> g(N, vector<uint>(N, INT_MAX));
    for (uint i = 0; i < M; i++) {
        uint a, b, w;
        cin >> a >> b >> w;

        --a;
        --b;
        g[a][b] = w;
        g[b][a] = w;
    }
    vector<bool> vis(N, false);

    vector<uint> dist_min = dijkstra(0u, g, vis);

    return EXIT_SUCCESS;
}
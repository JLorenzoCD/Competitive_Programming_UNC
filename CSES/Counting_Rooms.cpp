// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

const vector<pair<int, int>> MOVES = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool is_valid(int x, int y, uint n, uint m, vector<vector<bool>> &visitado) {
    if (x < 0 || y < 0 || (int)n <= x || (int)m <= y) {
        return false;
    }

    if (visitado[x][y]) {
        return false;
    }

    return true;
}

void dfs(uint x, uint y, vector<vector<bool>> &visitado) {
    visitado[x][y] = true;

    for (auto m : MOVES) {
        if (is_valid(x + m.first, y + m.second, visitado.size(), visitado[0u].size(), visitado)) {
            dfs(x + m.first, y + m.second, visitado);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N, M;
    cin >> N >> M;

    vector<vector<bool>> visitado(N, vector<bool>(M, false));
    vector<vector<bool>> g(N, vector<bool>(M));

    for (uint i = 0; i < N; ++i) {
        for (uint j = 0; j < M; ++j) {
            char c; cin >> c;
            if (c == '#') {
                visitado[i][j] = true;
            }
        }
    }

    uint ans = 0u;
    for (uint i = 0; i < N; i++) {
        for (uint j = 0; j < M; j++) {
            if (!visitado[i][j]) {
                dfs(i, j, visitado);
                ans++;
            }
        }

    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}
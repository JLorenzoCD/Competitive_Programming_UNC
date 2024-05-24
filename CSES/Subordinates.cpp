// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

uint tree_children(uint node, map<uint, vector<uint>> &tree, vector<uint> &subs) {
    subs[node] = 1u;
    for (uint children : tree[node]) {
        tree_children(children, tree, subs);

        subs[node] += subs[children];
    }

    return subs[node];
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N;
    cin >> N;

    map<uint, vector<uint>> tree;
    for (uint i = 1u; i < N; i++) {
        uint parent;
        cin >> parent;
        --parent;

        tree[parent].push_back(i);
    }

    vector<uint> subs(N);

    tree_children(0u, tree, subs);

    for (uint i = 0; i < N; i++) {
        cout << subs[i] - 1 << " ";
    }
    cout << endl;


    return EXIT_SUCCESS;
}
// https://codeforces.com/group/gmV7IkT2pN/contest/520377/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n;
    cin >> n;

    vector<pair<unsigned int, unsigned int>> g(n);
    for (pair<unsigned int, unsigned int>& e : g) {
        cin >> e.first >> e.second;
    }

    unsigned int count = 0u;
    for (unsigned int i = 0; i < n; i++) {
        pair<unsigned int, unsigned int> host = g[i];
        for (unsigned int j = 0; j < n; j++) {
            if (i == j) continue;

            if (host.first == g[j].second) {
                count++;
            }
        }

    }


    cout << count << endl;

    return EXIT_SUCCESS;
}
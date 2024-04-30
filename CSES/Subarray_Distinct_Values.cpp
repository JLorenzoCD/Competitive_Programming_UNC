// https://cses.fi/problemset/task/2428

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n, k;
    cin >> n >> k;

    vector<ull> x(n);
    for (ull& e : x) {
        cin >> e;
    }

    ull j = 0u;
    ull count = 0u;
    map<ull, ull> occur;
    for (ull i = 0u; i < n; i++) {
        while (j < n && (occur.size() < k || 0u < occur.count(x[j]))) {
            occur[x[j]]++;
            j++;
        }

        count += j - i;
        occur[x[i]]--;

        if (occur[x[i]] == 0u) {
            occur.erase(x[i]);
        }
    }

    cout << count << endl;

    return EXIT_SUCCESS;
}
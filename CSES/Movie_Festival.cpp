// https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n;
    cin >> n;

    vector<pair<ull, ull>> v(n);
    for (pair<ull, ull>& e : v) {
        cin >> e.second >> e.first;
    }

    sort(v.begin(), v.end());

    ull count = 0u;
    ull next = 0u;
    for (pair<ull, ull> e : v) {
        if (next <= e.second) {
            next = e.first;
            count++;
        }
    }

    cout << count << endl;

    return EXIT_SUCCESS;
}
// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull n, x;
    cin >> n >> x;

    vector<ull> p(n);
    for (ull &e : p) {
        cin >> e;
    }

    sort(p.begin(), p.end());

    ull count = 0u;
    ull l = 0u, r = n - 1u;
    while (l <= r && r > 0) {
        if (p[l] + p[r] <= x) {
            l++;
        }

        r--;
        count += 1u;
    }

    if (r == 0u && l == 0) {
        count += 1u;
    }

    cout << count << endl;

    return EXIT_SUCCESS;
}
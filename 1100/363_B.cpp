// https://codeforces.com/problemset/problem/363/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n, t;
    cin >> n >> t;

    vector<unsigned int> v(n);

    for (ull i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (ull i = 1; i < n; i++) {
        v[i] = v[i - 1u] + v[i];
    }

    ull best = v[t - 1u];
    ull best_i = 0;
    for (ull i = 0; (i <= n - t) && best != 1; i++) { // No hay mejor resultado que 1
        if (v[i + t] - v[i] < best) {
            best = v[i + t] - v[i];
            best_i = i + 1u;
        }
    }

    cout << (best_i + 1u) << endl;

    return EXIT_SUCCESS;
}

/*
7 3
1 2 6 1 1 7 1
== 3


1 1
100
== 1

2 1
10 20
== 1

10 5
1 2 3 1 2 2 3 1 4 5
== 1

10 2
3 1 4 1 4 6 2 1 4 6
== 7
*/

/*
    //! Peor caso t == n    ===>    O(n²)
    ull best = LONG_LONG_MAX;
    ull best_i = n;
    for (ull i = 0; i < n - t + 1u; i++) {
        ull sum = 0u;

        for (ull j = i; j < i + t; j++) {
            sum += v[j];
        }

        if (sum < best) {
            best = sum;
            best_i = i;
        }
    }

    cout << (best_i + 1u) << endl;
*/
// https://codeforces.com/contest/433/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef struct {
    unsigned int type;
    ull start;
    ull end;
} Questions;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n;
    cin >> n;

    vector<ll> v(n);
    vector<ll> copy_v(n);

    ll el;
    for (ull i = 0; i < n; i++) {
        cin >> el;

        v[i] = el;
        copy_v[i] = v[i];
    }
    sort(copy_v.begin(), copy_v.end());

    // Para evitar estar reaciendo la sumatoria, el elemento en la posicion i, es la sumatoria desde 0 hasta el elemento en i
    for (ull i = 1; i < n; i++) {
        v[i] = v[i - 1u] + v[i];
        copy_v[i] = copy_v[i - 1u] + copy_v[i];
    }

    ull m;
    cin >> m;

    vector<Questions> q(m);
    for (Questions& e : q) {
        cin >> e.type >> e.start >> e.end;
        e.start -= 1u;
        e.end -= 1u;
    }

    for (Questions e : q) {
        if (e.type == 2) {
            if (e.start == 0u) {
                cout << copy_v[e.end] << endl;
            }
            else {
                // Sumatoria desde 0 a i menos sumatoria desde 0 a j, siendo j < i
                cout << copy_v[e.end] - copy_v[e.start - 1] << endl;
            }
        }
        else {
            if (e.start == 0u) {
                cout << v[e.end] << endl;
            }
            else {
                // Sumatoria desde 0 a i menos sumatoria desde 0 a j, siendo j < i
                cout << v[e.end] - v[e.start - 1] << endl;
            }
        }
    }

    return EXIT_SUCCESS;
}
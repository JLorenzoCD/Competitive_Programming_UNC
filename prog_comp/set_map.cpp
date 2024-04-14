//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define fore(i, a, b) for(ull i = a; a < (b); i++)

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    set<ll> a;

    a.insert(0);

    a.size();   // Da un tam de 1

    a.insert(1);
    a.insert(1);

    a.size(); // Da un tam de 2, debido a que 1 se repite y no lo agrega

    a.insert(4);
    a.insert(6);

    a.erase(4); // Elimina el elemento 1

    auto x = a.lower_bound(3);

    if (x == a.end()) {
        // No existe
    }
    else {
        ll y = *x;
    }

    assert(a.rbegin() != a.rend());
    ll chico = *a.begin();
    ll grande = *a.rbegin();

    for (ll x : a) {
        // Recorrer un set
    }

    map<ll, ll> m;

    m[10] = 5;
    m[2] = 15;

    cout << m[0] << endl;

    for (auto [k, v] : m) {
        // Recorrer un Map con su key, value
    }

    if (m.count(0)) {
        // Entra si existe un elemento con key == 0
        m.erase(0);
    }

    return EXIT_SUCCESS;
}
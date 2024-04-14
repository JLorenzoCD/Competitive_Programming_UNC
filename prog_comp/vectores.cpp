//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define fore(i, a, b) for(ull i = a; a < (b); i++)

bool comp(ll a, ll b) {
    return abs(a) < abs(b);
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n;
    cin >> n;

    vector<ll> v(n);

    fore(i, 0, n) {
        cin >> v[i];
    }

    for (ll x : v) {
        // Lee todos los elementos de el arreglo
        cout << x << " ";
    }

    for (ll& x : v) {
        // Lee y permite modificar los valores de v
    }

    ull tam = v.size();

    // O(n log(n))
    sort(v.begin(), v.end());

    // Se le pede pasar una funcion que me retorne bool, para ver el orden ====> similar al goea_before() del lab
    sort(v.begin(), v.end(), comp);

    // Da vuelta a la lista
    reverse(v.begin(), v.end());

    // Estructura que permite agregar al inicio como al final, siimlar a vector
    deque<ll> d;

    d.push_front(4);
    d.push_back(1);

    // Un par de elementos, (dupla)
    pair<ll, ll> p;
    pair<ll, char> p;
    pair<ll, vector<int>> p;

    cin >> p.first >> p.second;

    return EXIT_SUCCESS;
}
// https://codeforces.com/group/gmV7IkT2pN/contest/520377/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int t;
    cin >> t;
    vector<ull> res(t);

    for (unsigned int i_t = 0; i_t < t; i_t++) {
        // Se obtinene la cantidad de elmentos del arreglo "a", al cual se le sumara la permutacion
        unsigned int n;
        cin >> n;

        // Se utiliza un set para evitar duplicados y ordenarlos
        set<ull> a;
        ull el;
        for (unsigned int i = 0; i < n; i++) {
            cin >> el;

            a.insert(el);
        }

        // Se pasan los elementos del set a un arreglo "v"
        vector<ull> v(a.size());
        unsigned int i = 0u;
        for (ull e : a) {
            v[i] = e;
            i++;
        }

        // Se crea y establece a 0u la variable que me dara la maxima cantidad de elementos iguales luego de la suma con una permutacion
        ull mx = 0u;
        for (unsigned int i = 0; i < v.size(); i++) {
            // Elemento a sumar con la permutacion
            ull curr = v[i];

            // Obtenecion del indice de el maximo elemento a los cuales puedo sumarle una permutacion [1, n]
            /*
            Ejemplo:
            n = 11
            elems = 2 1 19 1 8 12 16 7 2 5 8

            (en el set, ordenados y no repetidos)
            a = 1 2 5 7 8 12 16 19

            i = 0 => curr = 1
            El maximo numero que puedo obtener es sumandole n, lo cual me queda "12"
            Por lo que los unicos elementos a los que puedo sumale algun valor entre [1, n] son los que se encuentra menores a 12
                1     2     5     7     8     12     16     19
                |                              |
                ˅                              ˅
                curr                          max
                +11  +10   +7    +5     +4
                12   12    12    12     12

            Como todos son diferentes, entonces la suma para que me de un v[i] + n, hasta el lower_bound de v[i] + n, se va a realizar con diferentes valores de [1, n]
            */
            unsigned int m_i = lower_bound(v.begin(), v.end(), curr + n) - v.begin();

            mx = max(mx, ull(m_i - i));
        }

        res[i_t] = mx;
    }

    for (ull r : res) {
        cout << r << endl;
    }

    return EXIT_SUCCESS;
}

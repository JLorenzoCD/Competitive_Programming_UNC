// https://codeforces.com/group/gmV7IkT2pN/contest/520377/problem/F

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int q;
    cin >> q;

    while (q--) {
        ull n;
        cin >> n;

        vector<ull> p(n);
        for (ull& e : p) {
            cin >> e;
        }

        unsigned int x, y;
        ull a, b;
        cin >> x >> a;
        cin >> y >> b;

        // Siempre considero y < x, para evitar futuros ifs
        if (x < y) {
            ull temp;

            temp = x;
            x = y;
            y = temp;

            temp = a;
            a = b;
            b = temp;
        };

        ull k;
        cin >> k;

        // Ordenamiento desendente
        sort(p.rbegin(), p.rend());

        ull l, r;
        l = 0u;
        r = n + 1u;
        while (l < r) {
            // Esta forma de obtener el mid evita el overflow (si es que l y r son grandes, r + l posible overflow)
            ull mid = l + (r - l) / 2; // Exivalente (l + r)/2

            ull index = 0u;
            ull total = 0u;

            for (ull i = 1; i <= mid; i++) {
                // Minimo comun multiplo ( y < x, primeor descuento los MCM ya que obtengo la mayor ganancia)
                if (i % a == 0u && i % b == 0u) {
                    total += p[index] * (x + y);
                    index++;
                }
            }

            for (ull i = 1; i <= mid; i++) {
                // Multiplo de a y no de b ( y < x, segundo descuento los x)
                if (i % a == 0u && i % b != 0u) {
                    total += p[index] * (x);
                    index++;
                }
            }

            for (ull i = 1; i <= mid; i++) {
                // Multiplo de b y no de a ( y < x, tercero descuento los y)
                if (i % a != 0u && i % b == 0u) {
                    total += p[index] * (y);
                    index++;
                }
            }

            if (k * 100 <= total) {
                r = mid;
            }
            else {
                l = mid + 1u;
            }


        }

        if (n < l) {
            cout << -1 << endl;
        }
        else {
            cout << l << endl;
        }
    }

    return EXIT_SUCCESS;
}
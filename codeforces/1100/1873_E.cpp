// https://codeforces.com/problemset/problem/1873/E

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull t;
    cin >> t;

    vector<ull>res(t);
    for (ull k = 0; k < t; k++) {
        ull n, x;
        cin >> n >> x;

        vector<ull> a(n);
        for (ull& e : a) {
            cin >> e;
        }

        sort(a.begin(), a.end());

        // Se realiza una busqueda binarioa para obtener la altura necesaria para acomodar un maximo de x de agua
        ull l, r;
        l = 1u;
        r = LONG_LONG_MAX;
        while (l < r - 1u) {
            ull mid = (r + l) / 2; // La mitad del agua
            ull tot = 0u; // Cantidad de agua a la mitad de agua

            // En este bucle se calcula la cantidad de agua para una altura de mid
            for (ull i = 0; i < n; i++) {
                if (a[i] < mid) { // Veo si se puede añadir agua, es decir, que la altura del coral sea menor a la altura de la pesera
                    tot += (mid - a[i]); // Si es menor le sumo la diferencia para obtener el agua que puedo colocar en la i posicion
                }
            }

            // Se revisa si la cantidad de agua es mayor a la maxima cantidad de agua permitida
            if (x < tot) {
                r = mid; // Si es mayor a x, entonces realizo la siguiente busqueda desde un intervalo menor
            }
            else {
                // Todavia le queda espacio para poner agua
                l = mid;
            }
        }

        // l termina ciendo la maxima altura en la cual me llena hasta la maxima cantidad de agua permitida "x", o una cantidad inferior a esta pero maxima en cuanto a no sobrepasar x
        res[k] = l;
    }

    for (ull e : res) {
        cout << e << endl;
    }

    return EXIT_SUCCESS;
}
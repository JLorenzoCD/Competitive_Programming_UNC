// https://codeforces.com/problemset/problem/1701/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int t;
    cin >> t;

    while (t--) {
        // Numero de trabajadores y de tareas, los trabajadores realizan sus tareas en paralelo
        unsigned int n, m;
        cin >> n >> m;

        // Tareas
        map<unsigned int, unsigned int> tasks_per_worker;

        /*
        El valor de cada tarea representa el trabajador que es eficiente en esta
        Ej:
        1 1 1 1
        Significa que el trabajador 1 tarda 1 hora en realizar dicha tarea, cualquier otro trabajador tarda 2 horas

        5 1 3 2 4
        Significa que hay 5 trabajadores y cada uno de estos es eficiente en 1 tarea, tardando 1 hora en hacerce
        */
        for (unsigned int i = 1u; i <= n; i++) {
            tasks_per_worker[i] = 0u; // Set all workers with 0 tasks
        }

        for (unsigned int i = 0; i < m; i++) {
            unsigned int worker;
            cin >> worker;

            tasks_per_worker[worker]++; // Add task to worker
        }

        unsigned int ans = m * 2;
        unsigned int l, r;
        l = 1u;
        r = m * 2;
        while (l <= r) {
            unsigned int mid = l + (r - l) / 2; // Horas dadas para realizar la tareas

            unsigned int total_hours = 0u;
            unsigned int can_help = 0u;
            for (auto [key, value] : tasks_per_worker) {
                if (value <= mid) {
                    // El trabajador puede completar todas sus tareas en las que es bueno, por lo que puede ayudar a otros
                    can_help += (mid - value) / 2;
                }
                else {
                    total_hours += value - mid; // El trabajador no puede completar todas sus tareas en las que es bueno
                }
            }

            // Se revisa si el total de horas que un trabajador no puede con sus tareas, otro si puede ayudarlo
            if (total_hours <= can_help) {
                ans = mid;

                r = mid - 1u;
            }
            else {
                l = mid + 1u;
            }
        }

        cout << ans << endl;
    }

    return EXIT_SUCCESS;
}

/*
INPUT:
4
2 4
1 2 1 2
2 4
1 1 1 1
5 5
5 1 3 2 4
1 1
1


OUTPUT:
2
3
1
1
*/
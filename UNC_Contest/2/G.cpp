// https://codeforces.com/group/gmV7IkT2pN/contest/520377/problem/G

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n;
    cin >> n;

    priority_queue<ull> prevs;
    ull res = 0u;
    ll hp = 0;
    ll curr;
    for (ull i = 0; i < n; i++) {
        cin >> curr;

        if (0 <= curr) {
            // Si la posion me da salud la tomo

            res++;
            hp += curr;
        }
        else if (0 <= hp + curr) {
            // Aunque la posion me quita vida, esta no me mata
            res++;
            hp += curr;

            // Lo guardo en una priority_queue como su valor absoluto para poder copararlo luego
            prevs.push(abs(curr));
        }
        else if (prevs.size() != 0u) {
            // La posion me quita vida y me mata, y ya he tomado alguna posion que tambien me quito vida

            // Tengo que ver si la posion actual me quita menos que alguna que he tomado anteriormente para intercambiarla
            ll to_change = prevs.top();

            // No puedo intercambiarla por ninguna posion y me hace la vida negativa
            if (to_change <= abs(curr) && hp + curr < 0) {
                continue;
            }

            // Le sumo el valor de la posion intercambiada
            hp += to_change;
            prevs.pop();

            prevs.push(abs(curr));
            hp += curr;
        }
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}

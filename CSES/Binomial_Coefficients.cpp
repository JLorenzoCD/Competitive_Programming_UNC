// https://cses.fi/problemset/task/1079

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

const ull MOD = 1e9 + 7;
const ull MAX_N = 1e6 + 5;
ull fc[MAX_N], fci[MAX_N];

ull mul(ull a, ull b) {
    return (a * b) % MOD;
}

ull fpow(ull a, ull b) { // iterativa (mas rápida)
    ull res = 1;

    while (0 < b) {
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD, b /= 2;
    }

    return res;
}

void factoriales() {
    fc[0u] = 1;
    for (ull i = 1; i < MAX_N; ++i) {
        fc[i] = mul(fc[i - 1], i);
    }

    fci[MAX_N - 1] = fpow(fc[MAX_N - 1], MOD - 2);

    for (ull i = MAX_N - 2; 0u < i; i--) {
        fci[i] = mul(fci[i + 1], i + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N;
    cin >> N;

    vector<ull> res(N);

    factoriales();

    ull a, b;
    for (uint i = 0u; i < N; i++) {
        cin >> a >> b;

        if (b == 0u || b == a) {
            res[i] = 1u;
        }
        else if (b == 1u || a == (b - 1)) {
            res[i] = a;
        }
        else {
            /*
                (a!) / (b! * (a - b)!)
            */

            ull f_b = fc[b];            // b!
            ull f_dif = fc[a - b];     // (a - b)!

            ull f_div = mul(f_b, f_dif);       // (b! * (a - b)!)
            ull inv_div = fpow(f_div, MOD - 2);          // (b! * (a - b)!)^(-1)

            ull f_a = fc[a];

            res[i] = mul(f_a, inv_div);
        }
    }

    for (ull ans : res) {
        cout << ans << endl;
    }


    return EXIT_SUCCESS;
}
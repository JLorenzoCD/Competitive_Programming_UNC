// https://codeforces.com/group/gmV7IkT2pN/contest/522472/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    uint T;
    cin >> T;

    while (T--) {
        uint N, C;
        cin >> N >> C;

        map<uint, uint> A;
        for (uint i = 0u; i < N; i++) {
            uint el;
            cin >> el;

            if (A.count(el)) {
                A[el]++;
            }
            else {
                A[el] = 1u;
            }
        }

        uint ans = 0u;
        for (auto [kay, value] : A) {
            if (value < C) {
                ans += value;
            }
            else {
                ans += C;
            }
        }

        cout << ans << endl;
    }


    return EXIT_SUCCESS;
}
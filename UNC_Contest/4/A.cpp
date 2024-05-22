// https://codeforces.com/group/gmV7IkT2pN/contest/525522/problem/0

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
        uint N;
        cin >> N;

        uint b = 0u;
        uint temp_a, temp_b, j = 0u;
        for (uint i = 0; i < N; i++) {
            cin >> temp_a >> temp_b;

            if (temp_a <= 10u && b < temp_b) {
                j = i;
                b = temp_b;
            }
        }

        cout << j + 1 << endl;
    }


    return EXIT_SUCCESS;
}
// https://codeforces.com/problemset/problem/996/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef unsigned int uint;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull N;
    cin >> N;

    uint bills[] = { 100, 20, 10, 5, 1 };

    uint ans = 0u;
    for (uint i = 0u; i < 5u; i++) {
        ans += N / bills[i];
        N = N % bills[i];
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}
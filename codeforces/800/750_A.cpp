// https://codeforces.com/problemset/problem/750/A

#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;


int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // Contest start at 20:00hs, party start at 00:00hs - 4*6 minutos
    // Cada problema tarda 5 minutos

    uint N, K;
    cin >> N >> K;

    uint max_hour = 4 * 60;

    uint ans = 0u;

    uint l, r;
    l = 1u;
    r = N;
    while (l <= r) {
        uint mid = l + (r - l) / 2;

        uint time = ((mid * (mid + 1u)) / 2) * 5;

        if (time + K <= max_hour) {
            ans = mid;

            l = mid + 1u;
        }
        else {
            r = mid - 1u;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}
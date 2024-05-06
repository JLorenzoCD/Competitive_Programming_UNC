// https://codeforces.com/problemset/problem/991/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n;
    cin >> n;

    ull l, r;
    l = 1u;
    r = n;
    while (l < r) {
        ull mid = l + (r - l) / 2; // MID == K

        ull vasya_count = 0u;
        ull total_candies = n;
        while (0u < total_candies) {
            vasya_count += min(mid, total_candies);
            total_candies -= min(mid, total_candies); // Vasaye come "MID" caramelos
            total_candies -= (total_candies / 10); // Petya come 10% de los caramelos
        }

        bool can = ((n + 1u) / 2) <= vasya_count;
        if (can) {
            r = mid;
        }
        else {
            l = mid + 1u;
        }
    }

    cout << r << endl;

    return EXIT_SUCCESS;
}

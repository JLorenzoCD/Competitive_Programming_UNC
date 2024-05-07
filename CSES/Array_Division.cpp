// https://cses.fi/problemset/task/1085

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N, K;
    cin >> N >> K;

    ull max_el = 0u;
    ull sum = 0u;
    vector<ull> X(N);
    for (ull& el : X) {
        cin >> el;

        max_el = max(max_el, el);
        sum += el;
    }

    ull ans = sum;

    ull l, r;
    l = max_el;
    r = sum;
    while (l <= r) {
        ull mid = l + (r - l) / 2; // "MID" = max sum

        uint n_division = 1u;
        ull curr_sum = 0u;
        for (uint i = 0u; i < N; i++) {
            if (mid < curr_sum + X[i]) {
                n_division++;
                curr_sum = 0u;
            }

            curr_sum += X[i];
        }

        if (n_division <= K) {
            ans = min(mid, ans);

            r = mid - 1u;
        }
        else {
            l = mid + 1u;
        }
    }

    cout << ans << endl;


    return EXIT_SUCCESS;
}

/*
Input:
5 3
2 4 7 3 5

Output:
8
*/

// https://codeforces.com/problemset/gymProblem/102961/H

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned ll n;
    cin >> n;

    vector<ll> arr;

    ll el;
    for (size_t i = 0; i < n; i++) {
        cin >> el;
        arr.push_back(el);
    }

    ll max_sum, current_sum;
    max_sum = arr[0];
    current_sum = 0;

    for (size_t i = 0; i < n; i++) {
        current_sum = max(current_sum + arr[i], arr[i]);

        max_sum = max(current_sum, max_sum);
    }

    cout << max_sum << endl;

    return EXIT_SUCCESS;
}
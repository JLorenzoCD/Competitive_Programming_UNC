// https://codeforces.com/problemset/problem/158/A

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    /*
    n : Total number of participants who participated
    k : Minimum score to pass the round (k <= n)
    */
    unsigned int n, k;
    cin >> n >> k;

    unsigned int arr[n];
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unsigned int passed = 0;
    for (size_t i = 0; i < n; i++) {
        passed += arr[i] != 0 && arr[k - 1] <= arr[i] ? 1 : 0;
    }

    cout << passed << endl;

    return EXIT_SUCCESS;
}
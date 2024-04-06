// https://codeforces.com/problemset/problem/1742/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int t;
    cin >> t;

    bool arr[t];
    for (unsigned int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (max(a, b) == a) {
            arr[i] = a - b == c || a + b == c;
        }
        else {
            arr[i] = b - a == c || a + b == c;
        }
    }

    for (unsigned int i = 0; i < t; i++) {
        cout << (arr[i] ? "YES" : "NO") << endl;
    }

    return EXIT_SUCCESS;
}
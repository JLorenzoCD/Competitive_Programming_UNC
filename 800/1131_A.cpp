// https://codeforces.com/problemset/problem/1131/A

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned long int w1, h1, w2, h2;

    cin >> w1 >> h1 >> w2 >> h2;

    cout << (w1 + 2) * (h1 + h2 + 2) - w1 * (h1 + h2) << endl;

    return EXIT_SUCCESS;
}
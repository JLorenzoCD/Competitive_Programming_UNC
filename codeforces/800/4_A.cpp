// https://codeforces.com/problemset/problem/4/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    unsigned int w = 0;

    cin >> w;

    string res = w % 2 == 0 && (w - 2) != 0 && (w - 2) % 2 == 0 ? "YES" : "NO";
    cout << res << endl;

    return EXIT_SUCCESS;
}
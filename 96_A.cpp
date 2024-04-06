// https://codeforces.com/problemset/problem/96/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string situation;
    cin >> situation;

    bool is_dangerous = false;
    int count_0 = 0;
    int count_1 = 0;
    for (unsigned int i = 0; i < situation.length() && !is_dangerous; i++) {
        if (situation[i] == '1') {
            count_0 = 0;
            count_1 += 1;
        }
        else {
            count_1 = 0;
            count_0 += 1;
        }

        if (count_0 == 7 || count_1 == 7) {
            is_dangerous = true;
        }
    }

    cout << (is_dangerous ? "YES" : "NO") << endl;

    return EXIT_SUCCESS;
}
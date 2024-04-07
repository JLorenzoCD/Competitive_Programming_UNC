// https://codeforces.com/problemset/problem/617/A

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int x;
    cin >> x;

    unsigned int res = 0;
    while (0 < x) {
        if (0 <= (long int)(x - 5)) {
            x -= 5; res += 1;
        }
        else if (0 <= (long int)(x - 4)) {
            x -= 4; res += 1;
        }
        else if (0 <= (long int)(x - 3)) {
            x -= 3; res += 1;
        }
        else if (0 <= (long int)(x - 2)) {
            x -= 2; res += 1;
        }
        else {
            x -= 1; res += 1;
        }
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}
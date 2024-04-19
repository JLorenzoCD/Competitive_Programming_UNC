// https://codeforces.com/group/gmV7IkT2pN/contest/516385/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int t;
    cin >> t;

    vector<int> v(t);

    for (unsigned int i = 0; i < t; i++) {
        cin >> v[i];
    }

    for (int e : v) {
        if (e <= 1399) {
            cout << "Division 4" << endl;
        }
        else if (1400 <= e && e <= 1599) {
            cout << "Division 3" << endl;
        }
        else if (1600 <= e && e <= 1899) {
            cout << "Division 2" << endl;
        }
        else if (1900 <= e) {
            cout << "Division 1" << endl;
        }
    }

    return EXIT_SUCCESS;
}
// https://codeforces.com/group/gmV7IkT2pN/contest/516385/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull t;
    cin >> t;

    vector<ull> a(t);
    vector<ull> b(t);
    vector<ull> c(t);
    for (ull i = 0; i < t; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    ull m;
    unsigned int count;
    for (ull i = 0; i < t; i++) {
        count = 0u;

        m = max(a[i], max(b[i], c[i]));

        count += a[i] == m ? 1u : 0u;
        count += b[i] == m ? 1u : 0u;
        count += c[i] == m ? 1u : 0u;

        cout << (a[i] == m ? (count == 1 ? 0 : 1) : m - a[i] + 1u) << " ";
        cout << (b[i] == m ? (count == 1 ? 0 : 1) : m - b[i] + 1u) << " ";
        cout << (c[i] == m ? (count == 1 ? 0 : 1) : m - c[i] + 1u) << endl;
    }


    return EXIT_SUCCESS;
}
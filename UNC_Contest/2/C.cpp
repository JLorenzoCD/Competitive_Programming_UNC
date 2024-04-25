// https://codeforces.com/group/gmV7IkT2pN/contest/520377/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int t;
    cin >> t;

    vector<tuple<ull, ull, ull>> v(t);
    for (tuple<ull, ull, ull>& e : v) {
        cin >> get<0>(e) >> get<1>(e) >> get<2>(e);
    }


    ull count;
    tuple<ull, ull, ull> e;
    for (unsigned int i = 0; i < t; i++) {
        e = v[i];

        count = 0u;
        while (get<0>(e) <= get<2>(e) && get<1>(e) <= get<2>(e)) {
            if (get<0>(e) <= get<1>(e)) {
                get<0>(e) += get<1>(e);
            }
            else {
                get<1>(e) += get<0>(e);
            }

            count++;
        }

        cout << count << endl;
    }


    return EXIT_SUCCESS;
}
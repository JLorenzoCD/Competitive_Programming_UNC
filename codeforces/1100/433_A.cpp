// https://codeforces.com/contest/433/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n;
    cin >> n;

    map<unsigned int, unsigned int> m;
    m[200] = 0u;
    m[100] = 0u;

    unsigned int apple;
    for (unsigned int i = 0; i < n; i++) {
        cin >> apple;
        if (m.count(apple)) {
            m[apple] += 1u;
        }
        else {
            m[apple] = 1u;
        }
    }

    unsigned int sum = 0;
    if (m.count(100) != 0u) {
        sum += m[100] * 100;
    }
    if (m.count(200) != 0u) {
        sum += m[200] * 200;
    }

    unsigned int tf = sum / 2;

    unsigned int f1 = 0;
    unsigned int f2 = 0;

    unsigned int c = m[200];
    for (unsigned int i = 0; i < c; i++) {
        if (f1 + 200 <= tf) {
            f1 += 200;
            m[200] -= 1u;
        }
        else {
            f2 += 200;
            m[200] -= 1u;
        }
    }

    c = m[100];
    for (unsigned int i = 0; i < c; i++) {
        if (f1 + 100 <= tf) {
            f1 += 100;
            m[100] -= 1u;
        }
        else {
            f2 += 100;
            m[100] -= 1u;
        }
    }

    cout << ((f1 == tf && f2 == tf) ? "YES" : "NO") << endl;

    return EXIT_SUCCESS;
}
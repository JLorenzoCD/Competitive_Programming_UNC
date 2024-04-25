// https://codeforces.com/contest/1399/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef struct {
    unsigned int n;
    vector<unsigned int> a;
} TestCases;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int t;
    cin >> t;

    vector<TestCases> v(t);
    for (TestCases& tc : v) {
        cin >> tc.n;

        for (unsigned int i = 0; i < tc.n; i++) {
            unsigned int e;
            cin >> e;
            tc.a.push_back(e);
        }

        sort(tc.a.begin(), tc.a.end());
    }

    for (TestCases tc : v) {
        bool res = true;
        for (unsigned int i = 0; i < tc.n - 1u && res; i++) {
            if (1 < tc.a[i + 1u] - tc.a[i]) {
                res = false;
            }
        }

        cout << (res ? "YES" : "NO") << endl;
    }


    return EXIT_SUCCESS;
}
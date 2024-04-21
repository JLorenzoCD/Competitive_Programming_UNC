// https://codeforces.com/group/gmV7IkT2pN/contest/516385/problem/F

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int t;
    cin >> t;

    vector<string> v(t);
    for (string& e : v) {
        unsigned int n;
        cin >> n;

        cin >> e;
    }

    unordered_map<char, unsigned int> mp;
    unsigned int count;
    vector<unsigned int> counts(t);
    unsigned int ocurr;
    for (unsigned int k = 0u; k < t; k++) {
        count = 0u;

        for (unsigned int i = 0; i < v[k].size(); i++) {
            mp.clear();
            ocurr = 0u;

            for (unsigned int j = i; j < v[k].size() && j - i <= 100; j++) {
                char c = v[k][j];
                if (mp.count(c)) {
                    mp[c] += 1u;
                }
                else {
                    mp[c] = 1u;
                }

                if (10 < mp[c]) {
                    break;
                }

                ocurr = max(ocurr, mp[c]);
                if (ocurr <= mp.size()) {
                    count += 1u;
                }
            }
        }

        counts[k] = count;
    }

    for (unsigned int e : counts) {
        cout << e << endl;
    }

    return EXIT_SUCCESS;
}
// https://codeforces.com/contest/4/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n;
    cin >> n;

    map<string, unsigned int> mp;
    vector<string> v(n);

    string temp;
    for (unsigned int i = 0; i < n; i++) {
        cin >> temp;

        if (mp.count(temp)) {
            mp[temp] += 1u;

            temp += to_string(mp[temp] - 1u);
        }
        else {
            mp[temp] = 1u;
        }

        v[i] = mp[temp] == 1u ? "OK" : temp;
    }

    for (string s : v) {
        cout << s << endl;
    }

    return EXIT_SUCCESS;
}
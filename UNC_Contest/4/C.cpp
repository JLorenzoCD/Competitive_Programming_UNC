// https://codeforces.com/group/gmV7IkT2pN/contest/525522/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

void str_lower(string& s) {
    for (auto& c : s) {
        c = tolower(c);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N;
    cin >> N;

    map<string, uint> mp;
    for (uint i = 0; i < N; i++) {
        string name1, name2, _;
        cin >> name1 >> _ >> name2;

        str_lower(name1);
        str_lower(name2);

        if (!mp.count(name2)) {
            mp[name2] = 1u;
        }
        mp[name1] = max(mp[name2] + 1u, mp[name1]);
    }

    uint m = 0u;
    for (auto [s, r] : mp) {
        m = max(m, r);
    }

    cout << m << endl;

    return EXIT_SUCCESS;
}



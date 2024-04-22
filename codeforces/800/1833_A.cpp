// https://codeforces.com/contest/1833/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull t;
    cin >> t;

    vector<unsigned int> v(t);

    string s;
    unsigned int s_len;
    for (ull i = 0; i < t; i++) {
        cin >> s_len;
        cin >> s;

        set<string> st;
        for (unsigned int i = 0; i < s_len - 1; i++) {
            string temp = "";
            temp += s[i];
            temp += s[i + 1];

            st.insert(temp);
        }

        v[i] = st.size();
    }

    for (unsigned int e : v) {
        cout << e << endl;
    }

    return EXIT_SUCCESS;
}
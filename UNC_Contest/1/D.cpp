// https://codeforces.com/group/gmV7IkT2pN/contest/516385/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n;
    cin >> n;

    set<string> st;

    string s, c;
    for (unsigned int i = 0; i < n; i++) {
        cin >> s >> c;
        st.insert(s + "-" + c);
    }

    cout << st.size() << endl;

    return EXIT_SUCCESS;
}
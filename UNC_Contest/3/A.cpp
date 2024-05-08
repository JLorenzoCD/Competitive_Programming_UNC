// https://codeforces.com/group/gmV7IkT2pN/contest/522472/problem/0

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef unsigned int uint;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint T;
    cin >> T;

    while (T--) {
        uint N;
        cin >> N;

        unordered_set<char> st;

        char c;
        for (uint i = 0u; i < N; i++) {
            cin >> c;

            st.insert(c);
        }

        uint ans = st.size() * 2 + N - st.size();

        cout << ans << endl;
    }


    return EXIT_SUCCESS;
}
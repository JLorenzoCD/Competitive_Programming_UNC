// https://codeforces.com/group/gmV7IkT2pN/contest/525522/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N, M;
    cin >> N >> M;

    vector<uint> v(N, 0u);
    uint temp1, temp2;
    for (uint i = 0; i < M; i++) {
        cin >> temp1 >> temp2;
        temp1--;
        temp2--;

        v[temp1]++;
        v[temp2]++;
    }

    uint sum = 0u;
    for (uint el : v) {
        sum += el;
    }

    cout << sum << endl;

    return EXIT_SUCCESS;
}
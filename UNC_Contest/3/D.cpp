// https://codeforces.com/group/gmV7IkT2pN/contest/522472/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef unsigned int uint;

uint f(vector<uint>& A, vector<ll>& dp, uint curr_i) {
    if (A.size() == curr_i) { return 0u; }

    if (dp[curr_i] != -1) {
        return dp[curr_i];
    }

    dp[curr_i] = 1u + f(A, dp, curr_i + 1u);

    if (curr_i + 1u + A[curr_i] <= A.size()) {
        uint op1 = dp[curr_i];
        uint op2 = f(A, dp, curr_i + 1u + A[curr_i]);

        dp[curr_i] = min(op1, op2);
    }

    return dp[curr_i];
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint T;
    cin >> T;

    vector<uint> res(T);

    for (uint t = 0u; t < T; t++) {
        uint N;
        cin >> N;

        vector<uint> A(N);
        for (uint& el : A) {
            cin >> el;
        }

        vector<ll> dp(N, -1);

        res[t] = f(A, dp, 0u);
    }

    for (uint el : res) {
        cout << el << endl;
    }

    return EXIT_SUCCESS;
}


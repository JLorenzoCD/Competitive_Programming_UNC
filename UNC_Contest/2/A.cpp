// https://codeforces.com/group/gmV7IkT2pN/contest/520377/problem/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int t;
    cin >> t;


    vector<unsigned int> arr(3u);
    for (unsigned int i = 0; i < t; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];

        sort(arr.begin(), arr.end());

        cout << (arr[0] + arr[1] == arr[2] ? "YES" : "NO") << endl;
    }

    return EXIT_SUCCESS;
}
// https://codeforces.com/problemset/problem/1201/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull n, k;
    cin >> n >> k;

    vector<ull> a(n);
    for (ull &e : a) {
        cin >> e;
    }

    sort(a.begin(), a.end());

    ull i_median = n / 2;
    ull s = a[i_median];
    ull i = 1u;
    while (i <= i_median) {
        if (k < (a[i_median + i] * i - s))
            break;

        s += a[i_median + i];
        i++;
    }

    cout << ((k + s) / i) << endl;

    return EXIT_SUCCESS;
}

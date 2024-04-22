// https://codeforces.com/contest/4/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int d, sumTime;
    cin >> d >> sumTime;

    vector<pair<unsigned int, unsigned int>> a_p(d);

    unsigned int minTime, maxTime;
    for (unsigned int i = 0; i < d; i++) {
        cin >> minTime >> maxTime;
        a_p[i].first = minTime;
        a_p[i].second = maxTime;
    }

    minTime = 0u;
    maxTime = 0u;
    for (unsigned int i = 0; i < d; i++) {
        minTime += a_p[i].first;
        maxTime += a_p[i].second;
    }

    if (minTime <= sumTime && sumTime <= maxTime) {
        cout << "YES" << endl;

        for (unsigned int i = 0; i < d; i++) {
            cout << min(sumTime - minTime + a_p[i].first, a_p[i].second) << " ";
            sumTime -= min(sumTime - minTime + a_p[i].first, a_p[i].second);
            minTime -= a_p[i].first;
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return EXIT_SUCCESS;
}

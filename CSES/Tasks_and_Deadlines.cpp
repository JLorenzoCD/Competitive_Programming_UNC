// https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    uint N;
    cin >> N;

    vector<pair<uint, uint>> TASKS(N);
    for (pair<uint, uint>& task : TASKS) {
        cin >> task.first >> task.second; // frist = duracion de la tarea; second = fecha limite
    }

    sort(TASKS.begin(), TASKS.end());

    ll ans = 0u;
    ll start_time = 0u;
    for (pair<uint, uint>& task : TASKS) {
        start_time += task.first;

        ans += task.second - start_time;
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}

/*
Input:
3
6 10
8 15
5 12

Output:
2
*/
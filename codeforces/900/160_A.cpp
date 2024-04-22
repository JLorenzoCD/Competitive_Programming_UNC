// https://codeforces.com/problemset/problem/160/A

#include <bits/stdc++.h>

using namespace std;

int array_sum(unsigned int arr[], unsigned int start, unsigned int end);

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n;
    cin >> n;

    unsigned int arr[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n, greater<int>());

    unsigned int res = 1;
    unsigned int sum_0 = 0;
    unsigned int sum_1 = 0;
    for (unsigned int i = 1; i < n; i++) {
        sum_0 = array_sum(arr, 0, i - 1);
        sum_1 = array_sum(arr, i, n - 1);

        if (!(sum_1 < sum_0)) {
            res += 1;
        }
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}

int array_sum(unsigned int arr[], unsigned int start, unsigned int end) {
    int sum = 0;

    for (unsigned int i = start; i <= end; i++) {
        sum += arr[i];
    }

    return sum;
}
// https://codeforces.com/problemset/gymProblem/102961/H

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll max_subarray_sum(vector<ll> arr, ull len);

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull n;
    cin >> n;

    vector<ll> arr(n);

    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll best = max_subarray_sum(arr, n);

    cout << best << endl;

    return EXIT_SUCCESS;
}



ll max_subarray_sum(vector<ll> arr, ull len) {
    //! Solucion en O(n)
    ll max_sum, current_sum;
    max_sum = arr[0];
    current_sum = 0;

    for (ull i = 0; i < len; i++) {
        current_sum = max(current_sum + arr[i], arr[i]);

        max_sum = max(current_sum, max_sum);
    }

    return max_sum;
}


/*
ll max_subarray_sum_rec(vector<ll> arr, ull lft, ull rgt);


ll max_subarray_sum(vector<ll> arr, ull len) {
    //! Solucion en O(n*Log(n))
    return max_subarray_sum_rec(arr, 0u, (len == 0u ? 0u : len - 1u));
}

ll max_subarray_sum_rec(vector<ll> arr, ull lft, ull rgt) {
    // Caso base, solo hay un elemento
    if (rgt - lft == 0) {
        return arr[lft];
    }

    ull mid = (lft + rgt) / 2;

    // Divide
    ll msl = max_subarray_sum_rec(arr, lft, mid);
    ll msr = max_subarray_sum_rec(arr, mid + 1u, rgt);

    // Vencer
    ll max_sum_left = arr[mid];
    ll current_sum_left = 0;
    for (ull i = mid; i >= lft; i--) {
        current_sum_left += arr[i];

        max_sum_left = max(current_sum_left, max_sum_left);

        if (i == 0u) break;
    }

    ll max_sum_right = arr[mid + 1u];
    ll current_sum_right = 0;
    for (ull i = mid + 1u; i <= rgt; i++) {
        current_sum_right += arr[i];

        max_sum_right = max(current_sum_right, max_sum_right);
    }

    return max(max(msl, msr), max_sum_left + max_sum_right);
}
*/

/*
ll max_subarray_sum(vector<ll> arr, ull len) {
    //! Solucion en O(n²)
    ll best = arr[0];

    for (size_t i = 0; i < len; i++) {
        ll sum = 0;
        for (size_t j = i; j < len; j++) {
            sum += arr[j];
            best = max(best, sum);
        }
    }

    return best;
}
*/

/*
ll max_subarray_sum(vector<ll> arr, ull len) {
    //! Solucion en O(n³)
    ll best = arr[0];
    for (size_t i = 0; i < len; i++) {
        for (size_t j = i; j < len; j++) {
            ll sum = 0;
            for (size_t k = i; k <= j; k++) {
                sum += arr[k];
            }

            best = max(best, sum);
        }
    }

    return best;
}
*/

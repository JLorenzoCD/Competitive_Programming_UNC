// https://codeforces.com/group/gmV7IkT2pN/contest/520377/problem/E

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int n;
    cin >> n;

    /*
    ull sum = 0u;
    vector<ull> a(n);
    for (ull& e : a) {
        cin >> e;
        sum += e;
    }

    sort(a.begin(), a.end());

    unsigned int l, r;
    l = 0u;
    r = sum;

    ull maxel = a[n - 1u];
    ull res = sum;
    while (l <= r) {
        ull mid = (l + r) / 2;

        ull rounds = 0u;
        for (unsigned int i = 0; i < n && a[i] <= mid; i++) {
            rounds += mid - a[i];
        }

        if (mid <= rounds && maxel <= mid) {
            res = mid;
            r = mid - 1u;
        }
        else {
            l = mid + 1u;
        }
    }

    cout << res << endl;
    */

    ull sum = 0u;
    ull maxel = 0u;

    ull el;
    for (unsigned int i = 0; i < n; i++) {
        cin >> el;

        sum += el;
        maxel = max(maxel, el);
    }

    ull res = sum / (n - 1u);
    if (res < maxel) {
        res = maxel;
    }
    else if (res * (n - 1u) < sum) {
        res++;
    }

    cout << res << endl;

    return EXIT_SUCCESS;
}



/*
Input:
100
1 555 876 444 262 234 231 598 416 261 206 165 181 988 469 123 602 592 533 97 864 716 831 156 962 341 207 377 892 51 866 96 757 317 832 476 549 472 770 1000 887 145 956 515 992 653 972 677 973 527 984 559 280 346 580 30 372 547 209 929 492 520 446 726 47 170 699 560 814 206 688 955 308 287 26 102 77 430 262 71 415 586 532 562 419 615 732 658 108 315 268 574 86 12 23 429 640 995 342 305

Output:
1000

Input:
10
13 12 10 13 13 14 10 10 12 12

Output:
14

Input:
7
9 7 7 8 8 7 8

Output:
9

Input:
10
94 96 91 95 99 94 96 92 95 99

Output:
106

Input:
5
1000000000 5 5 4 4

Output:
1000000000
*/

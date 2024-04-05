/*
https://codeforces.com/problemset/problem/1/A

g++ -Wall -std=c++17 1_A.cpp -o ./main.out && ./main.out
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_VALUE pow(10, 9)
#define MIN_VALUE 1

long long division_with_rounding_up(long long x, long long y) {
    long long module_y = x % y;

    return x / y + (module_y != 0 ? 1 : 0);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    long long n = 0;
    long long m = 0;
    long long a = 0;

    cin >> n >> m >> a;

    long long flagstone_x = division_with_rounding_up(n, a);
    long long flagstone_y = division_with_rounding_up(m, a);

    long long number_of_flagstones = flagstone_x * flagstone_y;

    cout << number_of_flagstones << endl;

    return EXIT_SUCCESS;
}
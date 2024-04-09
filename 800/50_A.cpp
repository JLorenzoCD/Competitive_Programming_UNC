// https://codeforces.com/problemset/problem/50/A

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    /*
    M : Board width
    N : Board height
    */
    unsigned int M, N;
    cin >> M >> N;

    unsigned int number_of_dominoes = 0;

    number_of_dominoes = (M * N) / 2;

    cout << number_of_dominoes;

    return EXIT_SUCCESS;
}
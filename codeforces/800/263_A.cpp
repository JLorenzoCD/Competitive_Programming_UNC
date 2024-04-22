// https://codeforces.com/problemset/problem/263/A

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int LEN = 5;
    unsigned int matrix[LEN][LEN];

    unsigned int row;
    unsigned int col;
    for (size_t i = 0; i < LEN; i++) {
        for (size_t j = 0; j < LEN; j++) {
            cin >> matrix[i][j];

            if (matrix[i][j] == 1) {
                row = i;
                col = j;
            }
        }
    }

    unsigned int mov_row = row < 2 ? 2 - row : row - 2;
    unsigned int mov_col = col < 2 ? 2 - col : col - 2;

    cout << (mov_row + mov_col) << endl;

    return EXIT_SUCCESS;
}
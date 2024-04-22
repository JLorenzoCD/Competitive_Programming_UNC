/*
https://codeforces.com/problemset/problem/282/A

g++ -Wall -std=c++17 282_A.cpp -o ./main.out && ./main.out
*/

#include <bits/stdc++.h>

using namespace std;

char give_operation(string text) {
    unsigned int count_add = 0;

    for (unsigned int i = 0; i < 3; i++) {
        count_add += text[i] == '+' ? 1 : 0;
    }

    return count_add == 2 ? '+' : '-';
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int x = 0;
    unsigned int number_of_operations = 0;

    cin >> number_of_operations;

    string operation_text;
    for (unsigned int i = 0; i < number_of_operations; i++) {
        cin >> operation_text;

        if (give_operation(operation_text) == '+') {
            x++;
        }
        else {
            x--;
        }
    }

    cout << x << endl;

    return EXIT_SUCCESS;
}
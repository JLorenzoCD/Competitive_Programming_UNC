/*
https://codeforces.com/problemset/problem/231/A

g++ -Wall -std=c++17 231_A.cpp -o ./main.out && ./main.out
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    unsigned int number_of_problems = 0;

    cin >> number_of_problems;

    int problems_to_solve, petya_confidence, vasya_confidence, tonya_confidence;
    problems_to_solve = 0;
    for (unsigned int i = 0; i < number_of_problems; i++) {
        cin >> petya_confidence >> vasya_confidence >> tonya_confidence;

        problems_to_solve += petya_confidence + vasya_confidence + tonya_confidence >= 2 ? 1 : 0;
    }

    cout << problems_to_solve << endl;

    return EXIT_SUCCESS;
}
// https://codeforces.com/problemset/problem/71/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    unsigned int number_of_words = 0;
    cin >> number_of_words;

    string words[number_of_words];
    for (unsigned int i = 0; i < number_of_words; i++) {
        cin >> words[i];
    }

    for (unsigned int i = 0; i < number_of_words; i++) {
        if (10 < words[i].length()) {
            cout << words[i][0] << words[i].length() - 2 << words[i][words[i].length() - 1] << endl;
        }
        else {
            cout << words[i] << endl;
        }
    }

    return EXIT_SUCCESS;
}
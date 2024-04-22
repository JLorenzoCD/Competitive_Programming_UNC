// https://codeforces.com/problemset/problem/112/A

#include <bits/stdc++.h>

using namespace std;

string str_to_lower(string s);

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s1;
    string s2;

    cin >> s1 >> s2;

    s1 = str_to_lower(s1);
    s2 = str_to_lower(s2);

    int comparation = s1.compare(s2);

    if (comparation < 0) { comparation = -1; }
    else if (0 < comparation) { comparation = 1; }

    cout << comparation << endl;

    return EXIT_SUCCESS;
}

string str_to_lower(string s) {
    string str_lower;

    for (size_t i = 0; i < s.length(); i++) {
        str_lower += tolower(s[i]);
    }

    return str_lower;
}
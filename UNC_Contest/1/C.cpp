// https://codeforces.com/group/gmV7IkT2pN/contest/516385/problem/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


unsigned int count_X(string s);
string get_size(string s);

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ull t;
    cin >> t;

    map<string, ull> mp;
    mp["S"] = 1000;
    mp["M"] = 2000;
    mp["L"] = 3000;

    vector<pair<string, string>> v(t);

    for (unsigned int i = 0; i < t; i++) {
        cin >> v[i].first >> v[i].second;
    }


    pair <unsigned int, unsigned int> count;
    pair <string, string> sizes;
    for (unsigned int i = 0; i < t; i++) {
        count.first = count_X(v[i].first);
        count.second = count_X(v[i].second);

        sizes.first = get_size(v[i].first);
        sizes.second = get_size(v[i].second);

        count.first = (sizes.first == "S" ? mp[sizes.first] - count.first : count.first + mp[sizes.first]);
        count.second = (sizes.second == "S" ? mp[sizes.second] - count.second : count.second + mp[sizes.second]);


        if (count.first == count.second) {
            cout << "=" << endl;
        }
        else if (count.first < count.second) {
            cout << "<" << endl;
        }
        else if (count.first > count.second) {
            cout << ">" << endl;
        }
    }

    return EXIT_SUCCESS;
}

unsigned int count_X(string s) {
    unsigned int count = 0u;

    for (unsigned int i = 0; i < s.size(); i++)
        if (s[i] == 'X') count++;

    return count;
}

string get_size(string s) {
    string size_shirt;

    if (s.find("S") != string::npos) {
        size_shirt = "S";
    }
    else if (s.find("M") != string::npos) {
        size_shirt = "M";
    }
    else if (s.find("L") != string::npos) {
        size_shirt = "L";
    }

    return size_shirt;
}
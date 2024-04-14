//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define fore(i, a, b) for(ull i = a; a < (b); i++)

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    char c;
    cin >> c;

    // Son considerados numeros
    c++;

    cout << (int)c << endl;

    // Son el mismo output
    cout << (char)c << endl;
    cout << c << endl;

    // Solo en caracter
    c = tolower(c);
    c = toupper(c);

    // Lo que se vio en vectores, se puede realizar en strings
    string a, t;
    cin >> a >> t;

    if (a < t) {
        // Se realiza la ocmparacion en orden alfabetico
    }

    // Recorrer como un vector y pasar caracter por caracter a minuscula
    for (char& c : a) {
        c = tolower(c);
    }

    // Concadenar strings
    string s = a + t;

    return EXIT_SUCCESS;
}
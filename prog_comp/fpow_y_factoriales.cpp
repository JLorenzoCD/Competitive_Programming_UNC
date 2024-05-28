#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned int uint;

const ll MOD = 998244353; // o 1e9+7

int add(int a, int b) {
	a += b;
	if (MOD <= a) a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) a += MOD;

	return a;
}

int mul(ll a, ll b) {
	return (a * b) % MOD;
}

ll fpow(ll a, ll b) { // iterativa (mas rápida)
	ll res = 1;

	while (0 < b) {
		if (b % 2 == 1) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD, b /= 2;
	}

	return res;
}

ll binpow(ll a, ll b) { // recursiva
	if (b == 0) return 1;

	ll r = binpow(a, b / 2);

	if (b % 2 == 1) return (((r * r) % MOD) * a) % MOD;
	return (r * r) % MOD;
}

const ll MAXN = 1e6 + 5;
ll fc[MAXN], fci[MAXN];

void factoriales() {
	fc[0] = 1;
	for (ll i = 1;i < MAXN;++i) {
		fc[i] = mul(fc[i - 1], i);
	}

	fci[MAXN - 1] = fpow(fc[MAXN - 1], MOD - 2);

	for (ll i = MAXN - 2;i >= 0;i--)fci[i] = mul(fci[i + 1], i + 1);
}

ll comb(ll n, ll k) {
	return mul(fc[n], mul(fci[k], fci[n - k]));
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	factoriales();

	return 0;
}

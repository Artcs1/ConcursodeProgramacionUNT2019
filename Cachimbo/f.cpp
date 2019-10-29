#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli C1, C2;
lli X, Y;
lli mcmXY;

lli mcd (lli a, lli b) {
	return (b == 0 ? a : mcd(b, a % b));
}

lli mcm (lli a, lli b) {
	return a * (b / mcd(a, b));
}

bool f (lli V) {
	lli ambos = V / mcmXY;
	lli soloX = (V / X) - ambos;
	lli soloY = (V / Y) - ambos;

	lli complemento = V - soloX - soloY - ambos;

	return (max(0LL, C1 - soloY) + max(0LL, C2 - soloX)) <= complemento;
}

int main () {

	cin >> C1 >> C2 >> X >> Y;

	mcmXY = mcm(X, Y);

	lli ini = 0, fin = 10000000000, res;

	while (ini <= fin) {
		lli mid = (ini + fin) / 2;
		if (f(mid)) {
			res = mid;
			fin = mid - 1;
		}
		else {
			ini = mid + 1;
		}
	}

	cout << res << endl;

	return 0;
}
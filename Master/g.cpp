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

bool f (lli v) {
	lli ambos = (v / mcmXY);
	lli soloPrimero = (v / X) - ambos;
	lli soloSegundo = (v / Y) - ambos;

	lli complemento = v - soloPrimero - soloSegundo - ambos;

	return (max(0LL, C1 - soloSegundo) + max(0LL, C2 - soloPrimero)) <= complemento;
}

int main () {

	cin >> C1 >> C2 >> X >> Y;

	mcmXY = mcm(X, Y);

	lli ini = 0, fin = 10000000000, res;
	while (ini <= fin) {
		lli mid = (ini + fin) / 2;

		if (f(mid)) 	{
			res = mid;
			fin = mid - 1;
		}
		else
			ini = mid + 1;
	}

	cout << res << endl;

	return 0;
}
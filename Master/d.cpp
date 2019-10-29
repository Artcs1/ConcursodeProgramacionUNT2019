#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main () {

	lli N;
	lli K;

	cin >> N >> K;

	N = N / K;

	if (N % 2 != 0) cout << "SI" << endl;
	else cout << "NO" << endl;

	return 0;
}
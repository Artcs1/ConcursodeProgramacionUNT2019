#include <bits/stdc++.h>

using namespace std;

bool esPar (int n) {
	return n % 2 == 0;
}

/*

(esPar(A) && !esPar(B)) || (!esPar(A) && esPar(B))
(   A	  &&    !B    ) || (   !A	  &&    B    )   <=>   A xor B

*/

int main () {

	int A;
	int B;

	cin >> A >> B;
	while (!((A == B) || (esPar(A) xor esPar(B)) || (A > 1000 && B > 1000))) {
		cout << "TODAVIA NO" << endl;

		cin >> A >> B;
	}

	cout << "YA" << endl;

	return 0;
}
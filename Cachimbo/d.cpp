#include <bits/stdc++.h>

using namespace std;

int main () {

	string a, b, c;

	cin >> a >> b >> c;

	a.append(b);
	a.append(c);

	sort(a.begin(), a.end());

	cout << a[a.length() / 2] << endl; // 		7 / 2 = 3.5

	return 0;
}
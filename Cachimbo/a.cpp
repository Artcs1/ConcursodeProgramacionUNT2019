#include <bits/stdc++.h>

using namespace std;

// 64 -> 10101011000000
// 		 ^

char s[100+1];

int main () {

	cin >> s;

	int n = strlen(s);

	for (int i = 0 ; i < n ; i++) {
		if (s[i] == '1') {
			int cnt0 = 6;
			for (int j = i+1 ; j < n && cnt0 > 0; j++) {
				if (s[j] == '0') cnt0--;
			}

			if (cnt0 == 0) {
				cout << "si" << endl;
				return 0;
			}
		}
	}

	cout << "no" << endl;

	return 0;
}
#include <bits/stdc++.h>

#define MAX 10010

using namespace std;

int N;
int C[MAX];
int memo[MAX];

int dp (int idx) {
	if (memo[idx] != -1) return memo[idx];

	int res = 0;
	for (int i = idx+1 ; i < N ; i++) {
		if (C[i] % C[idx] == 0)
			res = max(res, 1 + dp(i));
	}

	return memo[idx] = res;
}

int main () {

	int n;

	cin >> n;

	N = n + 1;

	C[0] = 1;
	for (int i = 1 ; i <= n ; i++) {
		cin >> C[i];
	}

	sort(C, C+N);

	memset(memo, -1, sizeof memo);
	int mx = dp(0) - 1;
	for (int i = 1 ; i < N ; i++) {
		if (memo[i] == mx) {
			cout << C[i] << " ";
			mx--;
		}
	}


	return 0;
}
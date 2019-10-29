#include <bits/stdc++.h>

#define MAX 100100

using namespace std;

typedef vector<int> vi;

int N;
vector<vi> AdjList;

int grad[MAX];
int memo[MAX][2];
bool visited[MAX];

bool leaf (int v) {
	return grad[v] == 1;
}

int MVC (int v, int flag) {
	visited[v] = true;

	int ans = 0;

	if (memo[v][flag] != -1)	return memo[v][flag];
	else if (leaf(v)) ans = flag;
	else if (flag == 0) {
		ans = 0;
		for (int j = 0 ; j < (int) AdjList[v].size() ; j++) {
			if (!visited[AdjList[v][j]])
				ans += MVC(AdjList[v][j], 1);
		}
	}
	else if (flag == 1) {
		ans = 1;
		for (int j = 0 ; j < (int) AdjList[v].size() ; j++) {
			if (!visited[AdjList[v][j]])
				ans += min(MVC(AdjList[v][j], 1), MVC(AdjList[v][j], 0));
		}
	}

	visited[v] = false;

	return memo[v][flag] = ans;
}

int main () {

	int root = 1;
	int u;

	cin >> N;

	AdjList.assign(N+1, vi());
	memset(grad, 0, sizeof grad);

	for (int i = 1 ; i <= N-1 ; i++) {

		cin >> u;

		AdjList[u].push_back(i+1);
		AdjList[i+1].push_back(u);

		grad[u]++;
		grad[i+1]++;

		if (!leaf(u)) root = u;
		if (!leaf(i+1))	root = i+1;
	}

	memset(memo, -1, sizeof memo);
	memset(visited, 0, sizeof visited);

	cout << min(MVC(root, 0), MVC(root, 1)) << endl;

	return 0;
}
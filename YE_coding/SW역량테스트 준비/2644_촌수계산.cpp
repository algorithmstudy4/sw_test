//백준 https://www.acmicpc.net/problem/2644
//촌수계산
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100 + 1

using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> a >> b >> m;

	vector<vector<int>> dis(n + 1, vector<int>(n + 1, MAX));
	for (int i = 1; i <= n; i++) dis[n][n] = 0;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		dis[x][y] = dis[y][x] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	if (dis[a][b] != MAX) cout << dis[a][b];
	else cout << -1;

	return 0;
}
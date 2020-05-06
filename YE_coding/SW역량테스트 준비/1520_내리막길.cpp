// 백준 https://www.acmicpc.net/problem/1520
// 내리막길
#include<iostream>
#include<cstring>

using namespace std;

struct Dir {
	int x, y;
};

Dir dir[4] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

int N, M, arr[501][501], dp[501][501];

int DFS(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	if (x == 0 && y == 0) return 1;
	if (x < 0 || x >= M || y < 0 || y >= N) return 0;

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int xx = x + dir[i].x;
		int yy = y + dir[i].y;

		if (arr[xx][yy] > arr[x][y]) {
			dp[x][y] += DFS(xx, yy);
		}
	}

	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << DFS(M - 1, N - 1);

	return 0;
}
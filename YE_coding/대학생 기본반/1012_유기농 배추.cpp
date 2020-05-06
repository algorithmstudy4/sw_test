// 백준 https://www.acmicpc.net/problem/1012
// 유기농 배추
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct Dir {
	int x, y;
};

Dir dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int M, N, arr[50][50];
bool visit[50][50];

void BFS(int i, int j) {
	queue<Dir> q;
	q.push({ i, j });
	visit[i][j] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i].x;
			int yy = y + dir[i].y;
			if (xx < 0 || xx >= M || yy < 0 || yy >= N || visit[xx][yy] || !arr[xx][yy]) continue;

			visit[xx][yy] = true;
			q.push({ xx, yy });
		}
	}
}

int main() {
	int T, K, cnt;
	cin >> T;

	while (T--) {
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}

		cnt = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] && !visit[i][j]) {
					BFS(i, j); cnt++;
				}
			}
		}

		cout << cnt << '\n';
		memset(visit, false, sizeof(visit));
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}
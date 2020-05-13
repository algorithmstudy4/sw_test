// 백준 https://www.acmicpc.net/problem/7576
// 토마토
#include<iostream>
#include<queue>

using namespace std;

struct Dir {
	int y, x;
};

Dir dir[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int N, M, res, arr[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int total;
	cin >> M >> N;
	total = N * M;

	queue<Dir> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				total--;
				if (arr[i][j] == 1) q.push({ i, j });
			}
		}
	}

	while (!q.empty() && total) {
		int qsize = q.size();

		while (qsize--) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int yy = y + dir[i].y;
				int xx = x + dir[i].x;

				if (yy < 0 || yy >= N || xx < 0 || xx >= M || arr[yy][xx] != 0) continue;
				total--;
				arr[yy][xx] = 1;
				q.push({ yy, xx });
			}
		}
		res++;
	}

	if (total) cout << -1;
	else cout << res;

	return 0;
}
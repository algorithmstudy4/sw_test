// 백준 https://www.acmicpc.net/problem/2573
// 빙산
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct Dir {
	int x, y;
};

Dir dir[] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int n, m, time, cnt;
int arr[301][301], tmp[301][301];
bool flag, visit[301][301];

void BFS(int i, int j) {
	queue<pair<int, int>> q;
	visit[i][j] = true;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int xx = x + dir[k].x;
			int yy = y + dir[k].y;

			if (xx < 0 || xx >= n || yy < 0 || yy >= m || visit[xx][yy]) continue;

			if (arr[xx][yy] == 0) {
				cnt++;
				continue;
			}

			visit[xx][yy] = true;
			q.push(make_pair(xx, yy));
		}

		tmp[x][y] = cnt;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] || arr[i][j] == 0) continue;
				BFS(i, j);
				cnt++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] -= tmp[i][j];
				if (arr[i][j] < 0) arr[i][j] = 0;
			}
		}

		if (cnt > 1) { cout << time; break; }
		if (cnt == 0) { cout << 0; break; }

		time++;

		memset(tmp, 0, sizeof(tmp));
		memset(visit, false, sizeof(visit));
	}

	return 0;
}

// 백준 https://www.acmicpc.net/problem/3184
// 양
#include<iostream>
#include<queue>

using namespace std;

struct Dir {
	int y, x;
};

Dir dir[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int R, C, sheep, wolf;
char arr[250][250];
bool visit[250][250];

void BFS(int i, int j) {
	int s = 0, w = 0;

	visit[i][j] = true;
	queue<Dir> q;
	q.push({ i, j });

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		if (arr[y][x] == 'v') w++;
		else if (arr[y][x] == 'o') s++;

		for (int i = 0; i < 4; i++) {
			int yy = y + dir[i].y;
			int xx = x + dir[i].x;

			if (yy < 0 || yy >= R || xx < 0 || xx >= C || visit[yy][xx] || arr[yy][xx] == '#') continue;
			visit[yy][xx] = true;
			q.push({ yy, xx });
		}
	}

	if (s > w) wolf -= w;
	else sheep -= s;
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 'v') wolf++;
			else if (arr[i][j] == 'o') sheep++;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visit[i][j])
				BFS(i, j);
		}
	}

	cout << sheep << ' ' << wolf << '\n';
	return 0;
}

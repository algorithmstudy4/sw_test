// 백준 https://www.acmicpc.net/problem/4179
// 불!
#include<iostream>
#include<queue>

using namespace std;

struct Dir {
	int y, x;
};

Dir dir[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int R, C, res;
char arr[1000][1000];
bool flag, visit[1000][1000];

int main() {
	queue<Dir> q, fire;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'J') {
				arr[i][j] = '.';
				visit[i][j] = true;
				q.push({ i, j });
			}
			else if (arr[i][j] == 'F') fire.push({ i, j });
		}
	}

	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			if (y < 0 || y >= R || x < 0 || x >= C) {
				flag = true;
				break;
			}

			if (arr[y][x] == 'F') continue;

			for (int i = 0; i < 4; i++) {
				int yy = y + dir[i].y;
				int xx = x + dir[i].x;

				if (yy < 0 || yy >= R || xx < 0 || xx >= C) {
					q.push({ yy, xx });
					continue;
				}
				else if (visit[yy][xx] || arr[yy][xx] != '.') continue;

				visit[yy][xx] = true;
				q.push({ yy, xx });
			}
		}
		if (flag) break;

		res++;
		int fsize = fire.size();
		while (fsize--) {
			int y = fire.front().y;
			int x = fire.front().x;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int yy = y + dir[i].y;
				int xx = x + dir[i].x;

				if (yy < 0 || yy >= R || xx < 0 || xx >= C || arr[yy][xx] != '.') continue;
				arr[yy][xx] = 'F';
				fire.push({ yy, xx });
			}
		}
	}

	if (flag) cout << res;
	else cout << "IMPOSSIBLE";

	return 0;
}
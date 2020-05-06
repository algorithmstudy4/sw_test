// 백준 https://www.acmicpc.net/problem/11559
// Puyo Puyo
#include<iostream>
#include<queue>
#include <vector>
#include<cstring>

#define R 12
#define C 6

using namespace std;

char puyo[R][C];
bool visit[R][C];
vector<pair<int, int>> vec;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void update();
void connect(int, int);

int main() {
	int res = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> puyo[i][j];
		}
	}

	while (1) {
		for (int i = R - 1; i >= 0; i--) {
			for (int j = 0; j < C; j++) {
				if (puyo[i][j] == '.' || visit[i][j]) continue;
				connect(i, j);
			}
		}
		if (!vec.empty()) {
			for (int i = 0; i < vec.size(); i++)
				puyo[vec[i].first][vec[i].second] = '.';
			vec.clear();
			update();
			res++;
		}
		else break;
	}

	cout << res;
	return 0;
}

void connect(int a, int b) {
	char pu = puyo[a][b];
	queue < pair<int, int>> q;
	int cnt = 1;

	visit[a][b] = true;
	vec.push_back(make_pair(a, b));
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= R || yy < 0 || yy >= C || visit[xx][yy] || puyo[xx][yy] != pu) continue;

			visit[xx][yy] = true;
			vec.push_back(make_pair(xx, yy));
			q.push(make_pair(xx, yy));
			cnt++;
		}
	}

	if (cnt < 4)
		vec.erase(vec.end() - cnt, vec.end());
}

void update() {
	memset(visit, false, sizeof(visit));

	for (int i = R - 2; i >= 0; i--) {
		for (int j = 0; j < C; j++) {
			if (puyo[i][j] != '.') {
				int x = i;
				char pu = puyo[i][j];
				puyo[i][j] = '.';

				while (puyo[x + 1][j] == '.' && x != R - 1) {
					x++;
				}
				puyo[x][j] = pu;
			}
		}
	}
}
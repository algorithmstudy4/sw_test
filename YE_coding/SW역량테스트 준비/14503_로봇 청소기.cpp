// 백준 https://www.acmicpc.net/problem/14503
// 로봇청소기
#include<iostream>

using namespace std;

struct State {
	int x, y, dir;
};

int n, m, cnt;
int map[50][50];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int turn(int d) {
	if (d == 0) return 3;
	else return d - 1;
}

void clean(State s) {
	bool flag = false;
	int x = s.x;
	int y = s.y;
	int dir = s.dir;

	if (!map[x][y]) {
		cnt++;
		map[x][y] = -1;
	}

	for (int i = 0; i < 4; i++) {
		dir = turn(dir);
		int xx = x + dx[dir];
		int yy = y + dy[dir];

		if (!map[xx][yy]) {
			s.x = xx; s.y = yy; s.dir = dir;
			flag = true;
			break;
		}
	}

	if (!flag) {
		int back = turn(turn(dir));
		s.x += dx[back]; s.y += dy[back];
		if (map[s.x][s.y] == 1) return;
	}

	clean(s);
}

int main() {
	State start;
	cin >> n >> m;
	cin >> start.x >> start.y >> start.dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	clean(start);
	cout << cnt;
	return 0;
}
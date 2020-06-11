// 백준 https://www.acmicpc.net/problem/1726
// 로봇
#include<iostream>
#include<queue>

using namespace std;

int arr[101][101];
bool v[101][101][5];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

struct State {
	int x, y, dir;

	State(int a, int b, int c) {
		x = a; y = b; dir = c;
	}

	void visit() {
		v[x][y][dir] = true;
	}

	bool check_visit() {
		return v[x][y][dir];
	}
};

State Turn_dir(State s, bool right) {
	if (right) {
		if (s.dir == 1) s.dir = 3;
		else if (s.dir == 2) s.dir = 4;
		else if (s.dir == 3) s.dir = 2;
		else s.dir = 1;
	}
	else {
		if (s.dir == 1) s.dir = 4;
		else if (s.dir == 2) s.dir = 3;
		else if (s.dir == 3) s.dir = 1;
		else s.dir = 2;
	}

	return s;
}

State Go_k(State s, int k) {
	int xx, yy;

	for (int i = 1; i <= k; i++) {
		xx = s.x + i * dx[s.dir - 1];
		yy = s.y + i * dy[s.dir - 1];

		if (arr[xx][yy]) return s;
	}

	return State(xx, yy, s.dir);
}


int main() {
	int n, m, gx, gy, gd, cnt = 0;
	bool flag = false;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> gx >> gy >> gd;
	State start = State(gx, gy, gd);
	cin >> gx >> gy >> gd;

	queue<State> q;
	start.visit();
	q.push(start);

	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			State now = q.front();
			q.pop();

			if (now.x == gx && now.y == gy && now.dir == gd) {
				flag = true;
				break;
			}

			for (int i = 0; i < 2; i++) {
				State s = Turn_dir(now, i);
				if (arr[s.x][s.y] || s.check_visit()) continue;

				s.visit();
				q.push(s);
			}

			for (int i = 1; i < 4; i++) {
				State s = Go_k(now, i);
				if (s.x < 1 || s.y < 1 || s.x > n || s.y > m) continue;
				if (arr[s.x][s.y] || s.check_visit()) continue;

				s.visit();
				q.push(s);
			}
		}
		if (flag) break;
		else cnt++;
	}

	cout << cnt;
	return 0;
}
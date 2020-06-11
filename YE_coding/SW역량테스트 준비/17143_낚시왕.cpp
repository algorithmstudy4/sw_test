// 백준 https://www.acmicpc.net/problem/17143
// 낚시왕
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct shark {
	int x, y, speed, dir, size;
	bool eaten = false;

	bool operator <(const shark& s)const {
		return size > s.size;
	}
};

int R, C, M, sum;
bool isShark[101][101];
vector<shark> sh;

shark move_shark(shark s) {
	int sp = s.speed;
	if (s.dir == 1 || s.dir == 2) {
		sp = sp % (2 * (R - 1));
		if (s.dir == 1) s.x -= sp;
		else s.x += sp;

		while (1) {
			if (s.x > 0 && s.x <= R) break;

			if (s.x < 1) {
				s.x = 2 - s.x;
				s.dir = 2;
			}
			else {
				s.x = 2 * R - s.x;
				s.dir = 1;
			}
		}
	}
	else {
		sp = sp % (2 * (C - 1));
		if (s.dir == 3) s.y += sp;
		else s.y -= sp;

		while (1) {
			if (s.y > 0 && s.y <= C) break;

			if (s.y < 1) {
				s.y = 2 - s.y;
				s.dir = 3;
			}
			else {
				s.y = 2 * C - s.y;
				s.dir = 4;
			}
		}
	}

	return s;
}

void eat_shark() {
	memset(isShark, false, sizeof(isShark));

	for (int i = 0; i < sh.size(); i++) {
		if (sh[i].eaten) continue;
		sh[i] = move_shark(sh[i]);
		if (isShark[sh[i].x][sh[i].y]) sh[i].eaten = true;
		else isShark[sh[i].x][sh[i].y] = true;
	}
}

void catch_shark(int n) {
	int index = -1, min = 101;
	for (int i = 0; i < sh.size(); i++) {
		if (sh[i].eaten) continue;
		if (sh[i].y == n) {
			if (sh[i].x < min) {
				min = sh[i].x;
				index = i;
			}
		}
	}
	if (index != -1) {
		sum += sh[index].size;
		sh[index].eaten = true;
	}

	eat_shark();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int r, c, s, d, z;
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		isShark[r][c] = true;
		sh.push_back({ r, c, s, d, z });
	}

	sort(sh.begin(), sh.end());

	for (int i = 1; i < C + 1; i++) {
		catch_shark(i);
	}

	cout << sum;
	return 0;
}
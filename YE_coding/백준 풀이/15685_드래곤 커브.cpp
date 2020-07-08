//백준 https://www.acmicpc.net/problem/15685
//드래곤 커브
#include<iostream>
#include<vector>

using namespace std;

struct Point {
	int x, y;
};

bool check[101][101];
int dx[3] = { 0, 1, 1 };
int dy[3] = { 1, 0, 1 };

Point move(Point p, int d) {
	if (d == 0) p.x += 1;
	else if (d == 1) p.y -= 1;
	else if (d == 2) p.x -= 1;
	else p.y += 1;

	check[p.x][p.y] = true;

	return p;
}

int main() {
	int N;
	cin >> N;

	while (N--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<int> curve;
		check[x][y] = true;

		Point p = { x, y };
		curve.push_back(d);
		p = move(p, d);

		while (g--) {
			int s = curve.size() - 1;
			for (int i = s; i >= 0; i--) {
				int dir = (curve[i] + 1) % 4;
				curve.push_back(dir);
				p = move(p, dir);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (check[i][j]) {
				bool flag = true;

				for (int k = 0; k < 3; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (x < 0 || x > 100 || y < 0 || y > 100 || !check[x][y]) {
						flag = false;
						break;
					}
				}
				if (flag) cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}
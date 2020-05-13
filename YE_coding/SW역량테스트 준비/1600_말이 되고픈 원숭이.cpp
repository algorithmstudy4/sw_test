// 백준 https://www.acmicpc.net/problem/1600
// 말이 되고픈 원숭이
#include<iostream>
#include<queue>

using namespace std;

struct Monkey {
	int y, x, h;
};

struct Dir {
	int y, x;
};

int K, W, H, arr[201][201], res;
bool flag, visit[201][201][31];
Dir dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
Dir horse[8] = { {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2} };

int main() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}

	queue<Monkey> q;
	q.push({ 0, 0, K });
	visit[0][0][K] = true;

	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			int y = q.front().y;
			int x = q.front().x;
			int h = q.front().h;
			q.pop();

			if (y == H - 1 && x == W - 1) {
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int yy = y + dir[i].y;
				int xx = x + dir[i].x;

				if (yy < 0 || yy >= H || xx < 0 || xx >= W || visit[yy][xx][h] || arr[yy][xx]) continue;

				visit[yy][xx][h] = true;
				q.push({ yy, xx, h });
			}

			if (!h) continue;

			for (int i = 0; i < 8; i++) {
				int yy = y + horse[i].y;
				int xx = x + horse[i].x;
				int hh = h - 1;

				if (yy < 0 || yy >= H || xx < 0 || xx >= W || visit[yy][xx][hh] || arr[yy][xx]) continue;

				visit[yy][xx][hh] = true;
				q.push({ yy, xx, hh });
			}
		}
		if (flag) break;
		else res++;
	}

	if (!flag) cout << -1;
	else cout << res;

	return 0;
}
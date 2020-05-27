// 백준 https://www.acmicpc.net/problem/13460
// 구슬 탈출2
#include<iostream>
#include<queue>

using namespace std;

char arr[11][11];
bool check, v[11][11][11][11];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int main() {
	int n, m;
	int rx, ry, bx, by, ox, oy, cnt = 0;
	queue<pair<int, int>> red_q, blue_q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				red_q.push(make_pair(i, j));
				rx = i; ry = j;
			}
			else if (arr[i][j] == 'B') {
				blue_q.push(make_pair(i, j));
				bx = i; by = j;
			}
			else if (arr[i][j] == 'O') {
				ox = i; oy = j;
			}
		}
	}

	v[rx][ry][bx][by] = true;

	while (!red_q.empty()) {

		int qsize = red_q.size();

		for (int i = 0; i < qsize; i++) {

			rx = red_q.front().first;
			ry = red_q.front().second;
			bx = blue_q.front().first;
			by = blue_q.front().second;

			red_q.pop(); blue_q.pop();

			if (cnt > 10) break;

			if (rx == ox && ry == oy) {
				check = true;
				break;
			}

			for (int k = 0; k < 4; k++) {
				int drx = rx + dx[k];
				int dry = ry + dy[k];
				int dbx = bx + dx[k];
				int dby = by + dy[k];

				while (true) {
					if (arr[drx][dry] == '#') {
						drx -= dx[k]; dry -= dy[k];
						break;
					}
					if (arr[drx][dry] == 'O') break;
					drx += dx[k]; dry += dy[k];
				}

				while (true) {
					if (arr[dbx][dby] == '#') {
						dbx -= dx[k]; dby -= dy[k];
						break;
					}
					if (arr[dbx][dby] == 'O') break;
					dbx += dx[k]; dby += dy[k];
				}

				if (dbx == ox && dby == oy) continue;

				if (drx == dbx && dry == dby) {
					switch (k) {
					case 0: ry > by ? dry++ : dby++; break;
					case 1: rx > bx ? drx++ : dbx++; break;
					case 2: ry < by ? dry-- : dby--; break;
					case 3: rx < bx ? drx-- : dbx--; break;
					}
				}

				if (!v[drx][dry][dbx][dby]) {
					v[drx][dry][dbx][dby] = true;
					red_q.push(make_pair(drx, dry));
					blue_q.push(make_pair(dbx, dby));
				}
			}
		}
		if (check) break;
		else cnt++;
	}

	if (check) cout << cnt;
	else cout << "-1";

	return 0;
}
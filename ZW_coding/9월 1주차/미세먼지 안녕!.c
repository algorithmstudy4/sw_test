#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct posi {
	int first, second;
};
int R, C, T;
int map[50][50];
int temp[50][50];
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
struct posi cleaner[2];
int cptr;
void bfs(int x, int y) {
	int val = map[x][y];
	int rot = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		if (map[nx][ny] == -1) continue;
		temp[nx][ny] += val / 5;
		rot += 1;
	}
	map[x][y] -= rot * (val / 5);
}
void rotate() {
	int x = cleaner[0].first; int y = cleaner[0].second;
	for (int i = cleaner[0].first - 1; i >= 1; i--) {
		map[i][y] = map[i - 1][y];
	}
	for (int i = 0; i < C - 1; i++) {
		map[0][i] = map[0][i + 1];
	}
	for (int i = 0; i < x; i++) {
		map[i][C - 1] = map[i + 1][C - 1];
	}
	for (int i = C - 1; i >= 2; i--) {
		map[x][i] = map[x][i - 1];
	}
	map[x][y + 1] = 0;
	x = cleaner[1].first; y = cleaner[1].second;
	for (int i = x + 1; i < R - 1; i++) {
		map[i][0] = map[i + 1][0];
	}
	for (int i = 0; i < C - 1; i++) {
		map[R-1][i] = map[R - 1][i + 1];
	}
	for (int i = R - 1; i > x; i--) {
		map[i][C - 1] = map[i - 1][C - 1];
	}
	for (int i = C - 1; i >= 2; i--) {
		map[x][i] = map[x][i - 1];
	}
	map[x][y + 1] = 0;
}
void simul() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] >= 5) {
				bfs(i, j);
			}
			else continue;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += temp[i][j];
			temp[i][j] = 0;
		}
	}
	rotate();
}
int main() {
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				cleaner[cptr].first = i; cleaner[cptr].second = j;
				cptr += 1;
			}
		}
	}
	for (int t = 0; t < T; t++) {
		simul();
	}
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] > 0) ans += map[i][j];
		}
	}
	printf("%d\n", ans);
}

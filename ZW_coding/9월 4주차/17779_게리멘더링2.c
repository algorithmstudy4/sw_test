#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
struct posi {
	int first, second;
};
int N, ans = 987654321;
struct posi up, down, left, right;
int map[20][20];
int ok[20][20];
int d[20][20];
int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,-1,1};
void divide_map() {
	up.first = 987654321;
	left.second = 987654321;
	right.second = 0;
	down.first = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ok[i][j] = 0;
			if (d[i][j] == 1) {
				if (i < up.first) {
					up.first = i;
					up.second = j;
				}
				if (i > down.first) {
					down.first = i;
					down.second = j;
				}
				if (j > right.second) {
					right.first = i;
					right.second = j;
				}
				if (j < left.second) {
					left.first = i;
					left.second = j;
				}
			}
		}
	}
	int val[5] = { 0,0,0,0,0 };
	for (int i = 0; i < left.first; i++) {
		for (int j = 0; j <= up.second; j++) {
			if (d[i][j] == 1) break;
			val[0] += map[i][j];
			ok[i][j] = 1;
		}
	}
	for (int i = 0; i <= right.first; i++) {
		for (int j = N-1; j > up.second; j--) {
			if (d[i][j] == 1) break;
			val[1] += map[i][j];
			ok[i][j] = 1;
		}
	}
	for (int i = left.first; i < N; i++) {
		for (int j = 0; j < down.second; j++) {
			if (d[i][j] == 1) break;
			val[2] += map[i][j];
			ok[i][j] = 1;
		}
	}
	for (int i = right.first + 1; i < N; i++) {
		for (int j = N - 1; j >= down.second; j--) {
			if (d[i][j] == 1) break;
			val[3] += map[i][j];
			ok[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ok[i][j] == 0) {
				val[4] += map[i][j];
			}
		}
	}
	int mx = 0, mn = 987654;
	for (int i = 0; i < 5; i++) {
		if (val[i] > mx)
			mx = val[i];
		if (val[i] < mn)
			mn = val[i];
	}
	if (ans > mx - mn) {
		ans = mx - mn;
	}
}
void make_map(int x,int y,int sx,int sy, int dir) {
	if (dir != 0 && sx == x && sy == y) {
		divide_map();
		return;
	}
	for (int i = 0; i < 2; i++) {
		int nd = dir + i;
		if (nd >= 4) continue;
		int nx = x + dx[nd]; int ny = y + dy[nd];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (nx < sx) continue;
		if (d[nx][ny]) continue;
		d[nx][ny] = 1;
		make_map(nx, ny, sx, sy, nd);
		d[nx][ny] = 0;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &map[i][j]);
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			make_map(i, j, i, j, 0);
		}
	}
	printf("%d\n", ans);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, dir;
int map[20][4][4];
int t;
int ans, sum;
int X, Y;
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int XX, YY;
int nn;

struct FISH {
	int x, y;
	int d;
	int death;
}f[20];

int range(int x, int y) {
	if (x < 0 || y < 0 || x >= 4 || y >= 4) return -1;
	return 1;
}

void fmove(int dep) {
	for (int i = 1; i <= 16; i++) {
		f[i].death = 1;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			f[map[dep][i][j] % 100].x = j; f[map[dep][i][j] % 100].y = i; f[map[dep][i][j] % 100].death = 0; f[map[dep][i][j] % 100].d = map[dep][i][j] / 100;
		}
	}
	for (int i = 1; i <= 16; i++) {
		if (f[i].death == 0) {
			while (1) {
				X = f[i].x + dx[f[i].d]; Y = f[i].y + dy[f[i].d];
				if (range(X, Y) == 1&& map[dep][Y][X] % 100 != 17) {
					nn = map[dep][Y][X] % 100; XX = f[i].x; YY = f[i].y;
					f[i].x = X; f[i].y = Y; f[nn].x = XX; f[nn].y = YY;
					map[dep][Y][X] = i + (f[i].d * 100);
					map[dep][YY][XX] = nn + (f[nn].d * 100);
					break;
				}
				else {
					f[i].d++; if (f[i].d == 8)f[i].d = 0;
				}
			}
		}
	}
}

void sol(int dep, int x, int y) {
	fmove(dep);
	for (int l = 1; l <= 3; l++) {
		X = x + (l * dx[map[dep][y][x] / 100]);
		Y = y + (l * dy[map[dep][y][x] / 100]);
		if (range(X, Y) == 1 && map[dep][Y][X] != 0) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					map[dep + 1][i][j] = map[dep][i][j];
				}
			}
			map[dep + 1][y][x] = 0;
			map[dep + 1][Y][X] -= map[dep + 1][Y][X] % 100 - 17;
			sum += map[dep][Y][X] % 100;
			sol(dep + 1, X, Y);
			X = x + (l * dx[map[dep][y][x] / 100]);
			Y = y + (l * dy[map[dep][y][x] / 100]);
			sum -= map[dep][Y][X] % 100;
		}
	}
	if (sum > ans) {
		ans = sum;
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d %d", &n, &dir);
			map[0][i][j] += n;
			map[0][i][j] += (dir - 1) * 100;
		}
	}

	sum += map[0][0][0] % 100;
	map[0][0][0] -= map[0][0][0] % 100 - 17;

	sol(0,0,0);

	printf("%d", ans);

	return 0;
}

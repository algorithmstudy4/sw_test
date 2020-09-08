#include<stdio.h>
struct robot {
	int x, y, dir;
};
int N, M, map[50][50], ans;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
struct robot rb;
int rotate() {
	int nd = rb.dir + 4;
	for (int i = 0; i < 4; i++) {
		nd -= 1;
		int nx = rb.x + dx[nd % 4]; int ny = rb.y + dy[nd % 4];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (map[nx][ny] != 0) continue;
		rb.x = nx; rb.y = ny;
		rb.dir = nd % 4;
		return 1;
	}
	return 0;	
}
void solve() {
	while (1) {
		if (map[rb.x][rb.y] == 0) {
			map[rb.x][rb.y] = -1;
			ans += 1;
		}
		int tos = rotate();
		if (tos == 0) {
			int nd = rb.dir + 2;
			nd %= 4;
			int nx = rb.x + dx[nd]; int ny = rb.y + dy[nd];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
			if (map[nx][ny] == 1) break;
			rb.x = nx; rb.y = ny;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &rb.x, &rb.y, &rb.dir);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);
	solve();
	printf("%d\n", ans);
	return 0;
}

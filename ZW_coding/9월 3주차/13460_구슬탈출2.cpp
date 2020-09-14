#include<cstdio>
#include<queue>

using namespace std;

int N, M;
int rx, ry, bx, by, ex, ey, ans = 987654321;
char map[10][10];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
struct ball {
	int rx, ry, bx, by, cnt;
};
struct B {
	int rx, ry, bx, by;
};
bool d[10][10][10][10][4];

B moveRed(int x1, int y1, int x2, int y2, int dir) {
	int nx = x1; int ny = y1;
	bool ist = false;
	while (true) {
		nx += dx[dir]; ny += dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
		if (map[nx][ny] == '#') break;
		if (map[nx][ny] == 'O') {
			ist = true;
			break;
		}
	}
	if (!ist) {
		nx -= dx[dir]; ny -= dy[dir];
	}
	int nrx = nx; int nry = ny;

	nx = x2; ny = y2;
	ist = false;
	while (true) {
		nx += dx[dir]; ny += dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
		if (map[nx][ny] == '#') break;

		if (map[nx][ny] == 'O') {
			ist = true;
			break;
		}if (nx == nrx && ny == nry) break;
	}
	if (!ist) {
		nx -= dx[dir]; ny -= dy[dir];
	}
	int nbx = nx; int nby = ny;
	B b;
	b.rx = nrx; b.ry = nry; b.bx = nbx; b.by = nby;
	return b;
}

B moveBlue(int x1, int y1, int x2, int y2, int dir) {
	int nx = x2; int ny = y2;
	bool ist = false;
	while (true) {
		nx += dx[dir]; ny += dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
		if (map[nx][ny] == '#') break;
		if (map[nx][ny] == 'O') {
			ist = true;
			break;
		}
	}
	if (!ist) {
		nx -= dx[dir]; ny -= dy[dir];
	}
	int nbx = nx; int nby = ny;

	nx = x1; ny = y1;
	ist = false;
	while (true) {
		nx += dx[dir]; ny += dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
		if (map[nx][ny] == '#') break;

		if (map[nx][ny] == 'O') {
			ist = true;
			break;
		}if (nx == nbx && ny == nby) break;
	}
	if (!ist) {
		nx -= dx[dir]; ny -= dy[dir];
	}
	int nrx = nx; int nry = ny;
	B b; b.rx = nrx; b.ry = nry; b.bx = nbx; b.by = nby;
	return b;
}

void bfs() {
	queue<ball> q;
	q.push({ rx,ry,bx,by,0 });
	for (int i = 0; i < 4; i++)
		d[rx][ry][bx][by][i] = true;
	while (!q.empty()) {
		int x1 = q.front().rx; int y1 = q.front().ry;
		int x2 = q.front().bx; int y2 = q.front().by;
		int val = q.front().cnt;
		//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << val << '\n';
		q.pop();
		if (val > 10) {
			ans = -1;
			break;
		}
		if (x2 == ex && y2 == ey) continue;
		if (x1 == ex && y1 == ey) {
			if (ans > val)
				ans = val;
			return;
		}
		for (int i = 0; i < 4; i++) {
			switch (i) {
			case 0:
				if (y1 > y2) {
					B b = moveRed(x1, y1, x2, y2, 0);
					if (d[b.rx][b.ry][b.bx][b.by][0])continue;
					if (x1 == b.rx && y1 == b.ry && x2 == b.bx && y2 == b.by) continue;
					d[b.rx][b.ry][b.bx][b.by][0] = true;
					q.push({ b.rx, b.ry, b.bx, b.by, val + 1 });
				}
				else {
					B b = moveBlue(x1, y1, x2, y2, 0);
					if (d[b.rx][b.ry][b.bx][b.by][0])continue;
					if (x1 == b.rx && y1 == b.ry && x2 == b.bx && y2 == b.by) continue;
					d[b.rx][b.ry][b.bx][b.by][0] = true;
					q.push({ b.rx, b.ry, b.bx, b.by,val + 1 });
				}
				break;
			case 1:
				if (y1 < y2) {
					B b = moveRed(x1, y1, x2, y2, 1);
					if (d[b.rx][b.ry][b.bx][b.by][1])continue; if (x1 == b.rx && y1 == b.ry && x2 == b.bx && y2 == b.by) continue;
					d[b.rx][b.ry][b.bx][b.by][1] = true;
					q.push({ b.rx, b.ry, b.bx, b.by,val + 1 });
				}
				else {
					B b = moveBlue(x1, y1, x2, y2, 1);
					if (d[b.rx][b.ry][b.bx][b.by][1])continue; if (x1 == b.rx && y1 == b.ry && x2 == b.bx && y2 == b.by) continue;
					d[b.rx][b.ry][b.bx][b.by][1] = true;
					q.push({ b.rx, b.ry, b.bx, b.by,val + 1 });
				}
				break;
			case 2:
				if (x1 > x2) {
					B b = moveRed(x1, y1, x2, y2, 2);
					if (d[b.rx][b.ry][b.bx][b.by][2])continue; if (x1 == b.rx && y1 == b.ry && x2 == b.bx && y2 == b.by) continue;
					d[b.rx][b.ry][b.bx][b.by][2] = true;
					q.push({ b.rx, b.ry, b.bx, b.by,val + 1 });
				}
				else {
					B b = moveBlue(x1, y1, x2, y2, 2);
					if (d[b.rx][b.ry][b.bx][b.by][2])continue; if (x1 == b.rx && y1 == b.ry && x2 == b.bx && y2 == b.by) continue;
					d[b.rx][b.ry][b.bx][b.by][2] = true;
					q.push({ b.rx, b.ry, b.bx, b.by,val + 1 });
				}
				break;
			case 3:
				if (x1 < x2) {
					B b = moveRed(x1, y1, x2, y2, 3);
					if (d[b.rx][b.ry][b.bx][b.by][3])continue; if (x1 == b.rx && y1 == b.ry && x2 == b.bx && y2 == b.by) continue;
					d[b.rx][b.ry][b.bx][b.by][3] = true;
					q.push({ b.rx, b.ry, b.bx, b.by,val + 1 });
				}
				else {
					B b = moveBlue(x1, y1, x2, y2, 3);
					if (d[b.rx][b.ry][b.bx][b.by][3])continue; if (x1 == b.rx && y1 == b.ry && x2 == b.bx && y2 == b.by) continue;
					d[b.rx][b.ry][b.bx][b.by][3] = true;
					q.push({ b.rx, b.ry, b.bx, b.by,val + 1 });
				}
				break;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R')
			{
				rx = i; ry = j;
			}
			if (map[i][j] == 'B') {
				bx = i; by = j;
			}
			if (map[i][j] == 'O') {
				ex = i; ey = j;
			}
		}
	}
	bfs();
	if (ans == 987654321)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}

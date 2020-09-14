#include<stdio.h>
#include<string.h>
#define MAX 10000
struct pair {
	int first, second;
};
int N, M, ans = 987654321;
int map[50][50];
int d[50][50];
int v[50][50];
int av = 0;
struct pair q[MAX];
int wall = 0;
int ptr = 0;
int front, rear;
struct pair posi[11];
int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };
int bfs() {
	front = 0, rear = 0;
	int ret = 0;
	int virus = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == -1) {
				q[rear].first = i; q[rear].second = j;
				d[i][j] = 0;
				rear += 1;
			}
		}
	}
	while (rear != front) {
		int x = q[front].first; int y = q[front].second;
		front += 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (d[nx][ny] != -1) continue;
			if (map[nx][ny] == 1) continue;
			d[nx][ny] = d[x][y] + 1;
			
			if (map[nx][ny] == 0) {
				if (ret < d[nx][ny]) ret = d[nx][ny];
				
			}
			q[rear].first = nx, q[rear].second = ny;
			rear += 1;
			if(map[nx][ny] == 0)
				virus += 1;
		}
	}
	if (av  == virus) {
		return ret;
	}
	else
		return 987654321;
}
void go(int idx, int cnt) {
	if (cnt == M) {
		memset(d, -1, sizeof(d));
		int result = bfs();
		if (result < ans) ans = result;
		return;
	}
	if (idx >= ptr)
		return;
	go(idx + 1, cnt);
	v[posi[idx].first][posi[idx].second] = -1;
	go(idx + 1, cnt + 1);
	v[posi[idx].first][posi[idx].second] = 0;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		scanf("%d", &map[i][j]);
		if (map[i][j] == 2) {
			posi[ptr].first = i; posi[ptr].second = j;
			ptr += 1;
		}
		if (map[i][j] == 0)
			av += 1;
		if (map[i][j] == 1)
			wall += 1;
	}
	go(0, 0);
	if (ans == 987654321)
		ans = -1;
	printf("%d", ans);
	return 0;

}

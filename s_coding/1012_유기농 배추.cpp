#if 0
//유기농 배추
// https://www.acmicpc.net/problem/1012
#include <iostream>
#include <cstring> //memset
#define MAXN (50)
using namespace std;
int T, M, N, K;
int map[MAXN + 5][MAXN + 5];
int visited[MAXN + 5][MAXN + 5];
int dh[] = { -1,1,0,0 };
int dw[] = { 0,0,-1,1 };
void DFS(int h, int w) {

	visited[h][w] = 1;

	for (int i = 0; i < 4; i++) {
		int nh = h + dh[i];
		int nw = w + dw[i];

		if (visited[nh][nw] == 1 || map[nh][nw] == 0)continue;
		if (nh < 0 || nw < 0 || nh >= N || nw >= M)continue;

		DFS(nh,nw);
	}

}
void InputData() {

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int sol = 0;
		scanf("%d %d %d", &M, &N, &K);

		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		for (int k = 0; k < K; k++){
			int x, y;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {//세로
			for (int j = 0; j < M; j++) { //가로
				if (map[i][j] == 1 && visited[i][j] == 0) {
					DFS(i, j);
					//printf("%d %d\n", i, j);
					sol++;
				}
			}
		}
		printf("%d\n", sol);
	}
}
int main() {

	freopen("input.txt", "r", stdin);
	InputData();


	return 0;
}
#endif

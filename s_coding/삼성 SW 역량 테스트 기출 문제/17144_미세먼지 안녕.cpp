#if 01
//미세먼지 안녕
//https://www.acmicpc.net/problem/17144
#include <iostream>
#define MAXN (50)
using namespace std;

int R, C, T; //세로, 가로, 시간 
int map[2][MAXN + 5][MAXN + 5];
int up_h, up_w, down_h, down_w;
int dh[] = { -1,1,0,0 };
int dw[] = { 0,0,-1,1 };
int sol;
void spread(int cur) {
	int next = (cur + 1) % 2;

	//next map만들기 
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[cur][i][j] == -1) { //공기청정기 위치
				map[next][i][j] = -1;
			}
			else { // 나머지 배열 초기화
				map[next][i][j] = 0;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int quo = (map[cur][i][j] / 5);
			int sum_quo = 0;

			for (int d = 0; d < 4; d++) {
				int nh = i + dh[d];
				int nw = j + dw[d];

				if (nh < 0 || nw < 0 || nh >= R || nw >= C)continue;

				if (map[next][nh][nw] != -1) {
					map[next][nh][nw] += quo;
					sum_quo += quo; // 30은 12 6 6 6 quo는 6, sum_quo는 18
				}
			}

			if (map[next][i][j] != -1) {
				map[next][i][j] += (map[cur][i][j] - sum_quo); // map[next] 는 12
			}
		}	
	}
}
void move(int cur) {
	//위쪽은 반시계 방향
	// 1. 위-> 아래
	for (int h = up_h - 1; h > 0; h--) {
		map[cur][h][0] = map[cur][h - 1][0];
	}

	// 2. 오 -> 왼
	for (int w = 0; w < C - 1; w++) {
		map[cur][0][w] = map[cur][0][w + 1];
	}

	//3. 아 -> 위
	for (int h = 0; h < up_h; h++) {
		map[cur][h][C-1] = map[cur][h + 1][C-1];
	}

	//4. 왼 -> 오
	for (int w = C- 1; w > 1; w--) {
		map[cur][up_h][w] = map[cur][up_h][w - 1];
	}

	map[cur][up_h][1] = 0; //공기청정기에서 나오는 새 바람

	//아래쪽은 시계방향

	// 1. 아래 -> 위
	for (int h = down_h + 1; h < R; h++) {
		map[cur][h][0] = map[cur][h + 1][0];
	}

	for (int w = 0; w < C - 1; w++) {
		map[cur][R - 1][w] = map[cur][R - 1][w + 1];
	}

	for (int h = R - 1; h > down_h; h--) {
		map[cur][h][C - 1] = map[cur][h - 1][C - 1];
	}

	for (int w = C - 1; w > 1; w--) {
		map[cur][down_h][w] = map[cur][down_h][w - 1];
	}

	map[cur][down_h][1] = 0; //공기청정기에서 나오는 새 바람
}	
void InputData() {

	int flag = 1;
	scanf("%d %d %d", &R, &C, &T);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &map[0][i][j]);
			if (map[0][i][j] == -1) { //공기청정기 위치 저장 
				if (flag == 1) { //윗부분
					up_h = i;
					up_w = j;
					flag = 0;
				}
				else {
					down_h = i;
					down_w = j;
				}
			}
		}
	}

	int cur = 0;

	for (int t = 0; t < T; t++) {
		spread(cur); //확산
		cur = (cur + 1) % 2;
		move(cur); //공기 이동 
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[cur][i][j] != -1) { //공기청정기 아닌 부분 다 더해서 답 구함
				sol += map[cur][i][j]; 
			}
		}
	}
}
int main() {

	freopen("input.txt", "r", stdin);
	InputData();

	printf("%d", sol);

	return 0;
}
#endif

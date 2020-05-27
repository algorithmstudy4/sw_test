#if 0
//2048
//https://www.acmicpc.net/problem/12100
#include <iostream>
#define MAXN (20)
using namespace std;

int N,sol;
int map[MAXN + 2][MAXN + 2];

struct BOARD {
	int map[MAXN + 2][MAXN + 2];

	void rotate() {
		int tmp[MAXN + 2][MAXN + 2];

		for (int h = 0; h < N; h++) { //map 90도 회전해서 tmp에 넣음
			for (int w = 0; w < N; w++) {
				tmp[h][w] = map[N - w - 1][h];
			}
		}

		for (int h = 0; h < N; h++) { //tmp를 map에 다시 복사 
			for (int w = 0; w < N; w++) {
				map[h][w] = tmp[h][w];
			}
		}
	}

	int find_max() { //현재 map에서 최댓값 찾기 
		int max_val = 0;

		for (int h = 0; h < N; h++) { 
			for (int w = 0; w < N; w++) {
				if (max_val < map[h][w]) max_val = map[h][w];
			}
		}
		return max_val;
	}

	void up() {
		int tmp[MAXN + 2][MAXN + 2];

		for (int w = 0; w < N; w++){
			int flag = 0, target = -1;

			for (int h = 0; h < N; h++) {
				if (map[h][w] == 0)continue;
				if (flag == 1 && map[h][w] == tmp[target][w]) { //그 전에 변경안되었고 같은 수 있을 때
					tmp[target][w] *= 2;
					flag = 0; //한번 두배가 되면 다시 계산되면 안됨
				}
				else {
					tmp[++target][w] = map[h][w];
					flag = 1;
				}
			}

			for (target++; target < N; target++) {
				tmp[target][w] = 0;
			}
	
	    }

		for (int h = 0; h < N; h++) { //tmp를 map에 다시 복사 
			for (int w = 0; w < N; w++) {
				map[h][w] = tmp[h][w];
			}
		}
		
	}
};
BOARD board;

void DFS(BOARD cur, int cnt) {
	if (cnt == 5) { //최대 횟수 5번 
		int val = cur.find_max();

		if (sol < val) { //최대값 
			sol = val;
		}
		return;
	}

	for (int i = 0; i < 4; i++) { //네방향 돌면서
		BOARD next = cur;
		next.up();
		DFS(next,cnt + 1);
		cur.rotate();
	}
}
void InputData() {
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board.map[i][j]);
		}
	}
}
int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &N); //보드의 크기 

	InputData();
	DFS(board, 0);

	printf("%d", sol);

	return 0;
}
#endif

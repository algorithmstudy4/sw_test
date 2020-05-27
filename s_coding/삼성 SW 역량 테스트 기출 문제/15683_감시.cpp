#if 01
//감시
//https://www.acmicpc.net/problem/15683
#include <iostream>
#include <algorithm>
#define MAXN (8)
using namespace std;

struct CCTV {
	int h;
	int w;
	int type;
};

CCTV cctv[MAXN];
int cctv_size; //cctv개수 
int sol ; //사각 지대의 최소 크기
int map[MAXN][MAXN];
int H, W;
const int rotation[] = { 4,2,4,4,1 }; //회전할 수 있는 경우의 수 

void map_copy(int desc[MAXN][MAXN], int src[MAXN][MAXN]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			desc[i][j] = src[i][j];
		}
	}
}
void update(int dir, CCTV cctv) { //한 방향으로만 감시 
	dir = (dir % 4);
	//dir 0 - 우 1 - 상 2 - 좌 3 - 하 , 시계반대방향
	if (dir == 0) {
		for (int w = cctv.w + 1; w < W; w++) {//cctv가 비출수 있는 오른쪽으로만 영역 체크
			if (map[cctv.h][w] == 6)break; // 벽
			map[cctv.h][w] = -1;
		}
	}else if (dir == 1) {
		for (int h = cctv.h - 1; h >= 0; h--) {//위쪽 방향으로
			if (map[h][cctv.w] == 6)break; // 벽
			map[h][cctv.w] = -1;
		}
	}
	else if (dir == 2) {
		for (int w = cctv.w - 1; w >= 0 ; w--) {//cctv가 비출수 있는 왼쪽으로만 영역 체크
			if (map[cctv.h][w] == 6)break; // 벽
			map[cctv.h][w] = -1;
		}
	}
	else if (dir == 3) {
		for (int h = cctv.h + 1; h < H; h++) {//아래쪽 방향으로
			if (map[h][cctv.w] == 6)break; // 벽
			map[h][cctv.w] = -1;
		}
	}


}
void DFS(int idx) {
	if (idx == cctv_size) {//종료조건 , CCTV
		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 0) { //0의 개수=감시할 수 없는 영역
					cnt++;
				}
			}
		}

		if (sol > cnt) {//사각지대의 최소값 찾기
			sol = cnt; 
		}
		return;
	}
	
	int tmp[MAXN][MAXN];
	int type = cctv[idx].type;

	for (int dir = 0; dir < rotation[type]; dir++) { //각 CCTV별 경우의수, [4,2,4,4,1]만큼 회전
		//1.map 백업
		map_copy(tmp, map); //map을 tmp에 복사 

		//2.map 업데이트
		//update 한방향으로 cctv가 찍을 수 있는 곳 체크 
		//update는 화살표의 고정된 각도 
		if (type == 0) { //1번 -> 
			update(dir, cctv[idx]); //->
		}
		else if (type == 1) { //원래방향 + 180도방향 
			update(dir, cctv[idx]); //<-
			update(dir + 2, cctv[idx]); //->
		}
		else if (type == 2) { //원래 방향 + 90도방향
			update(dir, cctv[idx]); //위
			update(dir + 1, cctv[idx]); //->
		}
		else if (type == 3) { //원래 방향 + 90도방향 + 180도방향 
			update(dir, cctv[idx]); //<-
			update(dir + 1, cctv[idx]); //위
			update(dir + 2, cctv[idx]); //->
		}
		else if (type == 4) { //원래 방향 + 90도방향 + 180도방향 + 270도방향
			update(dir, cctv[idx]); //<-
			update(dir + 1, cctv[idx]); //위
			update(dir + 2, cctv[idx]); //->
			update(dir + 3, cctv[idx]); //아래
		}

		DFS(idx + 1);

		//3. map 복원 -백트래킹 
		map_copy(map,tmp);
	}

}
void InputData() {
	
	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6) { //0은 빈칸, 6은 벽 , 둘다 아니면 cctv
				//cctv의 좌표와 유형 저장
				cctv[cctv_size].h = i;
				cctv[cctv_size].w = j;
				cctv[cctv_size].type = map[i][j] - 1;  //인덱스 맞추기위해 
				cctv_size++;
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);

	InputData();

	sol = 100;
	DFS(0);

	printf("%d", sol);
	return 0;
}
#endif

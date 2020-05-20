#if 0
//연구소
//https://www.acmicpc.net/problem/14502
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm> //max
#define MAX 8
using namespace std;

int H, W; //세로 가로
int map[MAX][MAX];
int tmp[MAX][MAX]; // 벽 세우는 배열

int dh[] = { -1,1,0,0 };
int dw[] = { 0, 0,-1,1 };
int safe; //최종안전영역
void BFS() {
	//1.초기화
	queue< pair <int, int > > q;
	int spread[MAX][MAX]; //벽 세운 후 바이러스 퍼지는 배열
	int zerocnt = 0; //초기안전영역 
	int virus = 0; // 0->2 로 바뀐 것 


	memcpy(spread, tmp, sizeof(tmp));

	//2. 시작점
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (spread[i][j] == 0)zerocnt++;
			if (spread[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}

	//3. 반복문
	while (!q.empty()) {
		pair <int, int> cur;
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nh = cur.first + dh[i];
			int nw = cur.second + dw[i];

			if (nh < 0 || nw < 0 || nh >= H || nw >= W)continue;
			if (spread[nh][nw] == 0) {
				q.push({ nh,nw });
				spread[nh][nw] = 2; //감염됨 
			//	virus++;
			}
		}
	}


	//안전영역
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (spread[i][j] == 0)
				cnt += 1;
		}
	}
	safe = max(safe, cnt);
	//4. 결과
	//safe = max(safe, zerocnt - virus);

}
void wall(int cnt) {

	if (cnt == 3) {
		BFS(); //벽을 다 세우고 바이러스를 퍼뜨리러
		return;
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (tmp[i][j] == 0) { //벽을 세워도 됨
				tmp[i][j] = 1; //벽 세움
				wall(cnt + 1);
				tmp[i][j] = 0;
			}
		}
	}

}
void InputData() {

	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

}
void Solve() {

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 0) { //벽을 세워도 됨
				memcpy(tmp, map, sizeof(map));
				tmp[i][j] = 1; //첫번째 벽 세움 
				wall(1);
				tmp[i][j] = 0;
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);

	InputData();
	Solve();

	printf("%d", safe);
}

#endif

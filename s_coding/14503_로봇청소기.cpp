#if 01
//로봇 청소기 
//https://www.acmicpc.net/problem/14503

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 50

int N, M; //세로, 가로 
int r, c, dir;//청소기 좌표, 방향  
int cnt;
int map[MAX + 10][MAX + 10];
int visited[MAX + 10][MAX + 10];
int dh[] = { -1,0,1,0 }; //0:북, 1: 동 , 2:남 3: 서
int dw[] = { 0,1,0,-1 };
struct robot {
	int h;
	int w;
	int d;
};

int change_dir(int d) {
	return (d + 3) % 4;
}
void Solve() {
	
	
	map[r][c] = 2; //현재위치청소
	cnt = 1;

	while (1) {
		int flag = 0;
		robot cur;
		for (int i = 0; i < 4; i++) {

			cur.d = change_dir(dir);
			cur.h = r +  dh[cur.d];
			cur.w = c + dw[cur.d];
			dir = cur.d;

			if (map[cur.h][cur.w] == 0) {
				map[cur.h][cur.w] = 2;
				cnt++;
				r = cur.h;
				c = cur.w;
				flag = 1; // 청소 성공
				break; //한칸도 청소 못하면 dir = cur.d 청소하기 전의 처음방향상태
			}
			
		}

		if (flag == 0) { //후진
			//원래방향기준
			cur.h = r - dh[dir]; //후진
			cur.w = c - dw[dir];
			if (map[cur.h][cur.w] == 1)return;
			else {
				r -= dh[cur.d];
				c -= dw[cur.d];
			}
		}
	
	}


}
void InputData() {
	cin >> N >> M;
	cin >> r >> c >> dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);

	InputData();
	Solve();

	cout << cnt;


	return 0;
}

#endif

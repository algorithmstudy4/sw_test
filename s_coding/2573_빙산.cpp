#if 01
//빙산
//https://www.acmicpc.net/problem/2573
#include <iostream>
#include <cstring> //memset
#include <algorithm>
using namespace std;

int h, w;//세로,가로
int map[300 + 10][300 + 10];
int visited[300 + 10][300 + 10];
int dh[] = { -1,1,0,0 };
int dw[] = { 0,0,-1,1 };

void melt(int r,int c) {
	int meltcnt=0;

	for (int i = 0; i < 4; i++) {
		int nh = r + dh[i];
		int nw = c + dw[i];

		if (map[nh][nw] == -1) {
			meltcnt++;
		}
	}
	map[r][c] = map[r][c] - meltcnt;

	//다 녹으면
	if (map[r][c] <= 0)map[r][c] = 0; //map[r][c] -1이면 중복되서 개수 세짐 
}
void DFS(int r, int c) {
	visited[r][c] = 1;
	//cout << r << c <<endl;
	for (int i = 0; i < 4; i++) {
		int nh = r + dh[i];
		int nw = c + dw[i];

		if (map[nh][nw] == 0)map[nh][nw] = -1; //다음회차에 빙하를 녹이기 위해
		if (map[nh][nw] >= 1 &&visited[nh][nw]==0) {
			DFS(nh, nw);
		}
	}
}
int Solution() {
	
	int year=0;
	while (1) {
		int cur_ice = 0;//현재 빙하 개수
		int ice_cnt = 0;

		year++;
		memset(visited, 0, sizeof(visited));
		

		//빙하 돌면서 녹을 빙하 높이 계산 후 빙하 녹임
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] >= 1) {
					melt(i, j);
					cur_ice++;
				}
			}
		}
		//다 녹을 때까지 빙산이 한개면 , 더이상 녹을 빙산이 없으면
		if (cur_ice == 0)return 0;

		//dfs, 빙산 갯수 세기
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] >= 1 && visited[i][j] == 0) {
					DFS(i, j);
					ice_cnt++;
				}
			}
		}

		
		if (ice_cnt > 1)return year; //빙산이 분리되면
	}
	return -1; //실패
}
void InputData() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)map[i][j] = -1;
		}
	}
}
int main() {
	int sol;

	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	InputData();
	sol = Solution();

	cout << sol;


	return 0;
}

#endif

#if 0
//안전영역
//https://www.acmicpc.net/problem/2468

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100

int N; //행,열 개수
int maxh; //입력된 배열에서 가장 높은 높이 
int map[MAX + 10][MAX + 10];
int visited[MAX + 10][MAX + 10];
int safe[MAX + 10][MAX + 10]; //안전영역
int dh[] = { -1,1,0,0 };
int dw[] = { 0,0,-1,1 };

void Init() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			safe[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}
void DFS(int h,int w) { //재귀
	visited[h][w] = 1;

	for (int i = 0; i <4; i++) {
		int nh = h + dh[i];
		int nw = w + dw[i];

		if (safe[nh][nw] ==1 &&visited[nh][nw] ==0) {
			DFS(nh,nw);
		}
	}

}
void Solve() {
	
	int sol=0;

	for (int h = 1; h <= MAX; h++) { //높이
		Init(); //safe ,visited 배열초기화 
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] >= h) { //안전영역
					safe[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (safe[i][j] == 1 && visited[i][j]==0) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		sol = max(cnt, sol);
	}

	cout << sol;
}
void InputData() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxh)maxh = map[i][j];
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);

	InputData();
	Solve();

	

	return 0;
}

#endif

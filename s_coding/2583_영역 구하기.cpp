#if 01
//영역 구하기
//https://www.acmicpc.net/problem/2583
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;//세로, 가로, 직사각형개수
int map[100 + 10][100 + 10];
int visited[100 + 10][100 + 10];
int dh[] = { -1,1,0,0 };
int dw[] = { 0,0,-1,1 };
int area; //한 영역의 넓이 
vector <int> arr_area;

void Paint(int sw,int sh,int ew,int eh) {
	for (int i = sh; i < eh; i++) {
		for (int j = sw; j < ew; j++) {
			map[i][j] = 1;
		}
	}
}
void DFS(int h, int w) {
	visited[h][w] = 1;

	area++;
	for (int i = 0; i < 4; i++) {
		int nh = h + dh[i];
		int nw = w + dw[i];
		if (nh < 0 || nw < 0 || nh >= M || nw >= N)continue;
		if (visited[nh][nw] == 1)continue;
		if (map[nh][nw] == 0 && visited[nh][nw] == 0) {
			DFS(nh, nw);
		}
	}

}
void Solve() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && visited[i][j]==0) {
				DFS(i, j);
				if (area > 0) {
					arr_area.push_back(area);
					area = 0;
				}
			}
		}
	}

	cout << arr_area.size() << "\n";

	sort(arr_area.begin(), arr_area.end()); //오름차순 정렬

	for (int i = 0; i < arr_area.size(); i++) {
		cout << arr_area[i] << " ";
	}
}
void InputData() {
	int sw, sh, ew, eh;

	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> sw >> sh >> ew >> eh;
		Paint(sw, sh, ew, eh);
	}

}
int main() {
	InputData();
	Solve();

}
#endif

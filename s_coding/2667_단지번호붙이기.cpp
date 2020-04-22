#if 0
//단지 번호 붙이기
// https://www.acmicpc.net/problem/2667
#include <iostream>
#include <queue>
#include <algorithm> //sort
#include <utility>
using namespace std;

int map[25 + 10][25 + 10];
int visited[25 + 10][25 + 10]; //방문한 것 
int homesort[25 * 25 + 10];
int k; //배열의 개수 
int N;
queue <pair<int, int>> q;
int dh[] = { -1,1,0,0 };
int dw[] = { 0,0,-1,1 };

int BFS(int x, int y) {

	int home = 1;

	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nh = cur.first + dh[i];
			int nw = cur.second + dw[i];

			if (nh == 0 || nh > N || nw == 0 || nw > N)continue;
			if (map[nh][nw] == 0 || visited[nh][nw] == 1)continue;

			q.push({ nh,nw });
			visited[nh][nw] = 1;
			home++;

		}
	}

	return home;
}
int Solve() {
	int complex = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				homesort[k++] = BFS(i, j);
				complex++;
			}
		}

	}
	return complex;
}
void InputData() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}

	}
}
int main() {
	int sol;
	freopen("input.txt", "r", stdin);

	InputData();
	sol = Solve();
	sort(homesort, homesort + k);
	cout << sol << "\n";

	for (int i = 0; i < k; i++) {
		cout << homesort[i] << "\n";
	}

	return 0;
}

#endif

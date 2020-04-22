#if 0
//미로탐색- 구조체 + queue 쓸때
//https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;//세로, 가로
int map[100 + 10][100 + 10];
int visited[100 + 10][100 + 10];
int dh[] = { -1,1,0,0 }; //상하좌우
int dw[] = { 0,0,-1,1 };

typedef struct {
	int h;
	int w;
	int t;
}info;

int BFS() {
	
	queue <info> q;
	info cur;

	q.push({ 1, 1 ,1 });
	visited[1][1] = 1;

	while (!q.empty()) {

		cur = q.front();
		q.pop();

	
		if (cur.h == N && cur.w == M)return cur.t;

		for (int i = 0; i < 4; i++) {
			int nh = cur.h + dh[i];
			int nw = cur.w + dw[i];

			if (nh <= 0 || nh > N || nw <= 0 || nw > M)continue;
			if (map[nh][nw] == 0 || visited[nh][nw] == 1)continue;
			visited[nh][nw] = 1;
			q.push({ nh,nw,cur.t + 1 });
			//cout << nh << " " << nw << " " <<cur.t+1<< endl;
		}

	}

}
void InputData() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}
int main() {
	int sol;

	freopen("input.txt", "r", stdin);

	InputData();

	sol = BFS();
	cout << sol;
	return 0;
}

#endif

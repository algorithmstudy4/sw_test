#if 01
//촌수
//https://www.acmicpc.net/problem/2644

#include <iostream>
#include <queue>
using namespace std;

int n, m, st, ed; //전체사람수, 관계의 개수, 촌수 계산하는 두사람 
int adj[100 + 10][100 + 10];
int dist[100 + 10];//시작점(st)부터 배열인덱스(i)의 촌수(=dist[i]) 
queue <int> q;

int BFS() {
	
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (adj[cur][i] == 0 || dist[i] != 0) continue;
				dist[i] = dist[cur] + 1;
				q.push(i);
		
		}
	}

	if (dist[ed] == 0)return -1;
	else return dist[ed];
}
void InputData() {
	cin >> n >> st >> ed >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x][y] = adj[y][x] = 1;
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

#if 01
//연결 요소의 개수
//https://www.acmicpc.net/problem/11724
#include <iostream>
using namespace std;
int N, M;// 정점의 개수, 간선의 개수 
int adj[1000 + 10][1000 + 10];
int visited[1000 + 10];

void DFS(int v) {
	visited[v] = 1;

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1 || adj[v][i] == 0 || adj[i][v] == 0)continue;
		DFS(i);
	}
}
int main() {
	int cnt = 0;

	freopen("input.txt", "r", stdin);
	cin >> N >> M;

	for (int i = 0; i <M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			DFS(i);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
#endif

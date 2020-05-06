#if 01
//바이러스
//https://www.acmicpc.net/problem/2606

#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MAX 100

int com, N; // 컴퓨터 수 , 연결된 네트워크 쌍의 수 
int adj[MAX + 10][MAX + 10];
int visited[MAX + 10];
int cnt;

void DFS(int start) { //재귀

	visited[start] = 1;
	for (int i = 1; i <= com; i++) {

		if (adj[start][i] == 1 && visited[i] == 0) { 
			cnt++;
			DFS(i); 
		}
	}

}
void InputData() {
	int x, y;
	cin >> com >> N ;

	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		adj[x][y] = adj[y][x] = 1; //인접행렬 표시
	}
}
int main() {
	freopen("input.txt", "r", stdin);

	InputData();
	
	DFS(1);
	cout << cnt;

	return 0;
}

#endif

//https://www.acmicpc.net/problem/11724
//11724  연결요소의 개수

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define NMAX 1001

using namespace std;

int visited[NMAX];
stack<int> node_stack;
void DFS(vector<int> *graph,int x) {
	node_stack.push(x);
	visited[x] = 1;

	for (int i = 0; i < graph[x].size(); i++) {
		if (visited[graph[x][i]] == 0) {
			DFS(graph, graph[x][i]);
		}
	}

	node_stack.pop();
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> graph[NMAX];
	int node1, node2;
	while (M--) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	fill(visited, visited + N+1, 0);

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			DFS(graph,i);
			cnt++;
		}
	}

	cout << cnt;
}
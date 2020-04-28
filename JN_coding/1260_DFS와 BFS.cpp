//https://www.acmicpc.net/problem/1260
//DFS와 BFS

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

#define NMAX 1001
#define MMAX 10001

using namespace std;

stack<int> dfs;
void DFS(vector<int>* graph,int *visit,int check_node) {
	visit[check_node] = 1;
	cout << check_node << " ";

	for (int i = 0; i < graph[check_node].size(); i++) {
		if (visit[graph[check_node][i]] == 0) {
			dfs.push(graph[check_node][i]);
			DFS(graph, visit, graph[check_node][i]);
		}
	}
}

queue<int> bfs;
void BFS(vector<int>* graph, int* visit, int check_node) {
	bfs.push(check_node);
	visit[check_node] = 1;

	while (bfs.size() != 0) {
		check_node = bfs.front();
		cout << check_node << " ";

		for (int i = 0; i < graph[check_node].size(); i++) {
			if (visit[graph[check_node][i]] == 0) {
				bfs.push(graph[check_node][i]);
				visit[graph[check_node][i]] = 1;
			}
		}

		bfs.pop();
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	vector<int> graph[NMAX];

	int node1, node2;
	while (M--) {
		cin >> node1 >> node2;
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}

	//����
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	int visit[NMAX];
	fill(visit, visit + N+1, 0);

	DFS(graph,visit,V);
	cout << "\n";

	fill(visit, visit + N + 1, 0);
	BFS(graph,visit,V);
}

//2���� ���� ����

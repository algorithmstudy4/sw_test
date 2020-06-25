//백준 https://www.acmicpc.net/problem/11725
//트리의 부모 찾기
#include<iostream>
#include<vector>
#define MAX 100000 + 1

using namespace std;

int N, parent[MAX];
bool visit[MAX];
vector<int> tree[MAX];

void DFS(int node) {
	visit[node] = true;

	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];
		if (!visit[next]) {
			parent[next] = node;
			DFS(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}}
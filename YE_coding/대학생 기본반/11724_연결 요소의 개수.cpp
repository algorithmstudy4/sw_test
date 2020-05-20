// 백준 https://www.acmicpc.net/problem/11724
// 연결 요소의 개수
#include<iostream>
#include<vector>

using namespace std;

int N, M, cnt;
bool visit[1001];
vector<int> arr[1001];

void DFS(int n) {
	for (int i = 0; i < arr[n].size(); i++) {
		int next = arr[n][i];
		if (!visit[next]) {
			visit[next] = true;
			DFS(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			DFS(i);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
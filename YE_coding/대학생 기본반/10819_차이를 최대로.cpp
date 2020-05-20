// 백준 https://www.acmicpc.net/problem/10819
// 차이를 최대로
#include<iostream>

using namespace std;

int N, res, arr[9], order[9];
bool visit[9];

void DFS(int L) {
	if (L == N) {
		int tmp = 0;
		for (int i = 1; i < N; i++) {
			tmp += abs(arr[order[i - 1]] - arr[order[i]]);
		}
		res = res > tmp ? res : tmp;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			order[L] = i;
			DFS(L + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	DFS(0);
	cout << res;

	return 0;
}
// 백준 https://www.acmicpc.net/problem/14889
// 스타트와 링크
#include<iostream>
#include<vector>

using namespace std;

int n, sc[21][21], start[10], link[10], res = 2147000000;

void DFS(int L, int S, int p) {
	if (L == n / 2 && S == n / 2) {
		int s1, s2, l1, l2, s = 0, l = 0;
		for (int i = 0; i < L - 1; i++) {
			s1 = start[i];
			l1 = link[i];
			for (int j = i + 1; j < L; j++) {
				s2 = start[j];
				l2 = link[j];
				s += sc[s1][s2] + sc[s2][s1];
				l += sc[l1][l2] + sc[l2][l1];
			}
		}
		if (abs(s - l) < res) res = abs(s - l);
	}
	else if (p > n || L > n / 2 || S > n / 2) return;
	else {
		start[L] = p;
		DFS(L + 1, S, p + 1);
		link[S] = p;
		DFS(L, S + 1, p + 1);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> sc[i][j];
		}
	}

	DFS(0, 0, 1);
	cout << res;
}
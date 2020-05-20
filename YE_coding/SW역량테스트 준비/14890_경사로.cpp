// 백준 https://www.acmicpc.net/problem/14890
// 경사로
#include<iostream>
#include<cstring>

using namespace std;

int N, L, arr[100][100], res;

void check_pass(int n, int d) {
	int x, y, now;
	int dx[] = { 1, 0 };
	int dy[] = { 0, 1 };

	if (d == 0) { x = 0; y = n; }
	else { x = n; y = 0; }

	now = arr[x][y];

	int cnt = 1, prev = 0;
	for (int i = 1; i < N; i++) {
		x += dx[d];
		y += dy[d];
		int next = arr[x][y];

		if (abs(now - next) > 1) return;

		if (now > next) {
			if (cnt < 0) return;
			prev = -1;
			cnt = -L;
		}
		else if (now < next) {
			cnt -= L;
			if (cnt < 0) return;
			prev = 1;
		}

		cnt++;
		now = next;
	}
	if (prev == -1 && cnt < 0) return;

	res++;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int d = 0; d < 2; d++) {
			check_pass(i, d);
		}
	}

	cout << res;
	return 0;
}
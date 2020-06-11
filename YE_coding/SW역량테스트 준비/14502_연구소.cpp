// 백준 https://www.acmicpc.net/problem/14502
// 연구소
#include<iostream>
#include<queue>

using namespace std;

int n, m, arr[10][10], res = -2147000000;
bool v[10][10];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void virus() {
	int sum = 0, v_arr[10][10];
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v_arr[i][j] = arr[i][j];
			if (v_arr[i][j] == 2) q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || y >= m) continue;
			if (v_arr[xx][yy] == 0) {
				v_arr[xx][yy] = 2;
				q.push(make_pair(xx, yy));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v_arr[i][j] == 0) sum++;
		}
	}

	if (sum > res) res = sum;
}

void make_wall(int L) {
	if (L == 3) {
		virus();
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					make_wall(L + 1);
					arr[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	make_wall(0);

	cout << res;

	return 0;
}
//백준 https://www.acmicpc.net/problem/10026
//적록색약
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

bool visit[100][100];
char arr[100][100];
int N;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

bool check(char a, char b, bool flag) {
	if (!flag && a != b) return false;
	else if (flag && a != b) {
		if (a == 'B' || b == 'B') return false;
	}

	return true;
}

void BFS(int a, int b, bool flag) {
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		char now = arr[x][y];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= N || yy < 0 || yy >= N || visit[xx][yy]) continue;
			if (check(now, arr[xx][yy], flag)) {
				q.push(make_pair(xx, yy));
				visit[xx][yy] = true;
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < 2; k++) {
		int res = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					BFS(i, j, k);
					res++;
				}
			}
		}
		cout << res << ' ';
		memset(visit, false, sizeof(visit));
	}

	return 0;
}
//백준 https://www.acmicpc.net/problem/4485
//녹색 옷 입은 애가 젤다지?
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct Dir {
	int y, x;
};

int N, arr[125][125];
int memo[125][125];
Dir dir[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<Dir> q;

	for (int p = 1; ; p++) {
		cin >> N;
		if (!N) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		q.push({ 0, 0 });
		memset(memo, -1, sizeof(memo));
		memo[0][0] = arr[0][0];

		while (!q.empty()) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int yy = y + dir[i].y;
				int xx = x + dir[i].x;

				if (yy < 0 || xx < 0 || yy >= N || xx >= N) continue;

				int c = memo[y][x] + arr[yy][xx];
				if (memo[yy][xx] == -1 || memo[yy][xx] > c) {
					memo[yy][xx] = c;
					q.push({ yy, xx });
				}
			}
		}

		cout << "Problem " << p << ": " << memo[N - 1][N - 1] << "\n";
	}

	return 0;
}
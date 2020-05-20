// 백준 https://www.acmicpc.net/problem/2178
// 미로 탐색
#include<iostream>
#include<string>
#include<queue>

using namespace std;

struct Dir {
	int y, x;
};

Dir dir[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int N, M, res;
char arr[100][100];
bool flag, visit[100][100];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j];
		}
	}

	queue<Dir> q;
	q.push({ 0, 0 });
	visit[0][0] = true;

	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			int y = q.front().y;
			int x = q.front().x;
			q.pop();

			if (y == N - 1 && x == M - 1) {
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int yy = y + dir[i].y;
				int xx = x + dir[i].x;

				if (yy < 0 || xx < 0 || yy >= N || xx >= M || visit[yy][xx] || arr[yy][xx] == '0') continue;
				visit[yy][xx] = true;
				q.push({ yy, xx });
			}
		}
		res++;
		if (flag) break;
	}

	cout << res;
	return 0;
}
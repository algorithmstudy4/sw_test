//백준 https://www.acmicpc.net/problem/1194
//달이 차오른다, 가자.
#include<iostream>
#include<queue>

using namespace std;

struct Dir {
	int x, y;
};

struct state {
	int x, y, key; // 열쇠 소지 값, 비트마스크로 저장
};

Dir dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int n, m, res;
char arr[50][50];
bool flag, visit[50][50][1 << 6]; // 방문은 열쇠 소지 값까지 함께 체크

int main() {
	cin >> n >> m;

	queue<state> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				q.push({i, j, 0});
				visit[i][j][0] = true;
			}
		}
	}

	// BFS
	while (!q.empty()) {
		int qsize = q.size();

		while (qsize--) {
			int x = q.front().x;
			int y = q.front().y;
			int k = q.front().key;
			q.pop();

			// 탈출 발판
			if (arr[x][y] == '1') {
				flag = true;
				break;
			}

			// 열쇠 발판인 경우 현재 열쇠 소지 값 갱신
			if (arr[x][y] >= 'a' && arr[x][y] <= 'f') {
				k = k | 1 << (arr[x][y] - 'a');
			}

			for (int i = 0; i < 4; i++) {
				int xx = x + dir[i].x;
				int yy = y + dir[i].y;

				if (xx < 0 || xx >= n || yy < 0 || yy >= m || visit[xx][yy][k] || arr[xx][yy] == '#') continue; // 좌표 이탈 or 벽인 경우
				else if ((arr[xx][yy] >= 'A' && arr[xx][yy] <= 'F') && !(k & 1 << (arr[xx][yy] - 'A'))) continue; // 대응하는 열쇠가 없는 경우

				q.push({ xx, yy, k });
				visit[xx][yy][k] = true;
			}
			
		}
		if (flag) break;
		res++;
	}

	if (!flag) cout << -1;
	else cout << res;

	return 0;
}
// 백준 https://www.acmicpc.net/problem/16236
// 아기 상어
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int arr[20][20];
bool v[20][20];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

struct state {
	int x, y, dis;

	bool operator<(const state& s) const {
		if (dis != s.dis) return dis > s.dis;
		else if (x != s.x) return x > s.x;
		return y > s.y;
	}
};

struct Shark {
	int x, y, size, eat;
	void sizeUp() {
		eat++;
		if (eat == size) {
			eat = 0;
			size++;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, res = 0;
	cin >> n;

	Shark shark;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				shark = { i, j, 2, 0 };
				arr[i][j] = 0;
			}
		}
	}

	priority_queue<state> q;
	v[shark.x][shark.y] = true;
	q.push({ shark.x, shark.y, 0 });
	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int dis = q.top().dis;
		q.pop();

		if (arr[x][y] != 0 && arr[x][y] < shark.size) {
			shark.x = x;
			shark.y = y;
			shark.sizeUp();
			arr[x][y] = 0;

			while (!q.empty()) q.pop();
			memset(v, false, sizeof(v));
			v[x][y] = true;
			res = dis;
		}

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || xx >= n || yy < 0 || yy >= n || v[xx][yy] || arr[xx][yy] > shark.size) continue;
			v[xx][yy] = true;
			q.push({ xx, yy, dis + 1 });
		}
	}

	cout << res;
	return 0;
}
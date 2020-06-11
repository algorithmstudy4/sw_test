// 백준 https://www.acmicpc.net/problem/16234
// 인구 이동
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int arr[50][50], N, L, R;
bool flag, v[50][50];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void BFS(int a, int b) {
	int sum = 0;
	queue<pair<int, int>> q;
	vector<pair<int, int>> vec;

	q.push(make_pair(a, b));
	vec.push_back(make_pair(a, b));
	sum = arr[a][b];
	v[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int value = arr[x][y];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int diff = abs(value - arr[xx][yy]);

			if (xx < 0 || xx >= N || yy < 0 || yy >= N || diff < L || diff > R || v[xx][yy]) continue;
			v[xx][yy] = true;
			flag = true;
			q.push(make_pair(xx, yy));
			vec.push_back(make_pair(xx, yy));
			sum += arr[xx][yy];
		}
	}

	sum /= vec.size();
	for (int i = 0; i < vec.size(); i++) {
		int x = vec[i].first;
		int y = vec[i].second;
		arr[x][y] = sum;
	}
}

int main() {
	int time = 0;
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!v[i][j]) {
					BFS(i, j);
				}
			}
		}

		if (flag) time++;
		else break;

		//memset(v, false, sizeof(v));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				v[i][j] = false;
			}
		}
	}

	cout << time;
	return 0;
}
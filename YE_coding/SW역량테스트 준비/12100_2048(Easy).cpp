// 백준 https://www.acmicpc.net/problem/12100
// 2048 (Easy)
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct Block {
	int x, y;
	bool isUse;
};

struct Dir {
	int x, y;
};

Dir dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int N, arr[20][20], temp[20][20], comb[5], res;
bool isMerge[20][20];
vector<Block> block, bt;

bool cmp_up(const Block& a, const Block& b) {
	return a.x < b.x;
}

bool cmp_right(const Block& a, const Block& b) {
	return a.y > b.y;
}

bool cmp_down(const Block& a, const Block& b) {
	return a.x > b.x;
}

bool cmp_left(const Block& a, const Block& b) {
	return a.y < b.y;
}

void DFS(int);
void Moving(int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];

			if (arr[i][j] > 0) block.push_back({ i, j, true });
		}
	}

	DFS(0);

	cout << res;
	return 0;
}

void DFS(int L) {
	if (L == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i][j] = arr[i][j];
			}
		}
		bt = block;

		for (int i = 0; i < 5; i++) {
			Moving(comb[i]);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				res = res > temp[i][j] ? res : temp[i][j];
			}
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		comb[L] = i;
		DFS(L + 1);
	}
}

void Moving(int D) {
	if (D == 0) sort(bt.begin(), bt.end(), cmp_up);
	else if (D == 1) sort(bt.begin(), bt.end(), cmp_right);
	else if (D == 2) sort(bt.begin(), bt.end(), cmp_down);
	else sort(bt.begin(), bt.end(), cmp_left);

	for (int i = 0; i < bt.size(); i++) {
		if (!bt[i].isUse) continue;

		int x = bt[i].x;
		int y = bt[i].y;
		int s = temp[x][y];
		bool flag = false;

		temp[x][y] = 0;
		while (true) {
			x += dir[D].x; y += dir[D].y;
			if (x < 0 || x >= N || y < 0 || y >= N) break;
			else if (temp[x][y] != 0) {
				flag = true;
				break;
			}
		}
		if (flag && !isMerge[x][y] && s == temp[x][y]) {
			temp[x][y] += s;
			isMerge[x][y] = true;
			bt[i].isUse = false;
		}
		else {
			x -= dir[D].x; y -= dir[D].y;
			bt[i].x = x;
			bt[i].y = y;
			temp[x][y] = s;
		}
	}
	memset(isMerge, false, sizeof(isMerge));
}
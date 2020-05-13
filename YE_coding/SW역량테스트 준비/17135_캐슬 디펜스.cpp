// 백준 https://www.acmicpc.net/problem/17135
// 캐슬 디펜스
#include<iostream>
#include<vector>
#define MAX 2147000000

using namespace std;

struct Enemy {
	int y, x;
};

int N, M, D, res, arr[16][16], hunter[3];

void Hunt() {
	int tmp[16][16], cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = arr[i][j];
		}
	}

	int index = 0;
	while (index < N) {
		vector<int> target;

		for (int k = 0; k < 3; k++) {
			int h = hunter[k];
			int idx, dis, m = MAX;

			for (int j = M - 1; j >= 0; j--) {
				for (int i = N - 1; i >= index; i--) {
					if (tmp[i][j]) {
						dis = abs(N - i) + abs(h - j);
						if (dis <= D && dis <= m) {
							m = dis;
							idx = M * i + j;
						}
					}
				}
			}

			if (m == MAX) continue;
			target.push_back(idx);
		}

		for (int i = 0; i < target.size(); i++) {
			int y = target[i] / M;
			int x = target[i] % M;
			if (tmp[y][x]) {
				tmp[y][x] = 0;
				cnt++;
			}
		}

		for (int i = N - 1; i >= index; i--) {
			for (int j = M - 1; j >= 0; j--) {
				if (i == N - 1) tmp[i][j] = 0;
				else if (tmp[i][j]) {
					tmp[i + 1][j] = tmp[i][j];
					tmp[i][j] = 0;
				}
			}
		}
		index++;
	}
	res = res > cnt ? res : cnt;
}

void choose(int L, int i) {
	if (L == 3) {
		Hunt();
		return;
	}
	if (i >= M) return;

	hunter[L] = i;
	choose(L + 1, i + 1);
	choose(L, i + 1);
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	choose(0, 0);
	cout << res;

	return 0;
}
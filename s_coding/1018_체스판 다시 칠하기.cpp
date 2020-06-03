#if 01
//체스판 다시 칠하기
//https://www.acmicpc.net/problem/1018
#include <iostream>
#include <algorithm>

using namespace std;

char board[51][51];
int n, m;
int result = 50 * 50;

void search(int y, int x) {
	if (y + 8 > n || x + 8 > m) return;

	int sumw = 0;
	int sumb = 0;
	int sum = 0;
	int checker = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (checker == 0) {
				if (board[y + i][x + j] == 'B') {
					sumw++;
				}
				else sumb++;
			}
			else {
				if (board[y + i][x + j] == 'W') {
					sumw++;
				}
				else sumb++;
			}
			checker++;
			checker %= 2;
		}
		checker++;
		checker %= 2;
	}

	sum = min(sumw, sumb);
	result = min(sum, result);
}

int main() {
  freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			search(i, j);
		}
	}

	cout << result;
}
#endif

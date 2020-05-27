// 백준 https://www.acmicpc.net/problem/1018
// 체스판 다시 칠하기
#include<iostream>
#include<string>

using namespace std;

string black[8] = { {"BWBWBWBW"},
					{"WBWBWBWB"},
					{"BWBWBWBW"},
					{"WBWBWBWB"},
					{"BWBWBWBW"},
					{"WBWBWBWB"},
					{"BWBWBWBW"},
					{"WBWBWBWB"} };

string white[8] = { {"WBWBWBWB"},
					{"BWBWBWBW"},
					{"WBWBWBWB"},
					{"BWBWBWBW"},
					{"WBWBWBWB"},
					{"BWBWBWBW"},
					{"WBWBWBWB"},
					{"BWBWBWBW"} };

int N, M, res = 2147000000;
string str[50];

void check(int y, int x) {
	int cnt = 0;

	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (str[i][j] != black[i - y][j - x]) cnt++;
		}
	}
	res = res < cnt ? res : cnt;

	cnt = 0;
	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if (str[i][j] != white[i - y][j - x]) cnt++;
		}
	}
	res = res < cnt ? res : cnt;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			check(i, j);
		}
	}

	cout << res;
	return 0;
}
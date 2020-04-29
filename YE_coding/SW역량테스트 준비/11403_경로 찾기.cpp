//백준 https://www.acmicpc.net/problem/11403
//경로 찾기
#include<iostream>
#include<vector>
#define MAX 100

using namespace std;

int N, arr[MAX][MAX];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (!arr[i][j]) {
				arr[i][j] = MAX;
			}
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = arr[i][j] < arr[i][k] + arr[k][j] ? arr[i][j] : arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == MAX) cout << 0 << ' ';
			else cout << 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
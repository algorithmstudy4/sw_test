//백준 https://www.acmicpc.net/problem/9095
//1,2,3 더하기
#include<iostream>
#include<algorithm>

using namespace std;

int dp[11][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1][1] = 1; dp[2][2] = 1; dp[3][3] = 1;

	for (int i = 2; i < 11; i++) {
		for (int j = 1; j < 4; j++) {
			int index = i - j;
			if (index < 1) continue;

			dp[i][j] = dp[index][1] + dp[index][2] + dp[index][3];
		}
	}

	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		cout << dp[N][1] + dp[N][2] + dp[N][3] << '\n';
	}

	return 0;
}
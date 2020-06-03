// 백준 https://www.acmicpc.net/problem/11048
// 이동하기
#include<iostream>
#include<algorithm>

using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> dp[i][j];

			int res;
			res = max(dp[i - 1][j], dp[i][j - 1]);
			res = max(res, dp[i - 1][j - 1]);
			dp[i][j] += res;
		}
	}

	cout << dp[N][M];

	return 0;
}
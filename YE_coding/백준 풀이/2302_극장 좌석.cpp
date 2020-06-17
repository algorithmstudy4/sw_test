//백준 https://www.acmicpc.net/problem/2302
//극장 좌석
#include<iostream>

using namespace std;

int N, M, cnt, res = 1, dp[41];
bool check[41];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		check[a] = true;
	}

	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	for (int i = 1; i <= N; i++) {
		if (check[i]) {
			if (!cnt) continue;
			res *= dp[cnt];
			cnt = 0;
		}
		else cnt++;
	}

	if (cnt) res *= dp[cnt];

	cout << res << '\n';

	return 0;
}
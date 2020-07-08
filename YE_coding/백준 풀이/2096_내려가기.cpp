//백준 https://www.acmicpc.net/problem/2096
//내려가기
#include<iostream>
#include<algorithm>

using namespace std;

int max_dp[3], min_dp[3];

int main() {
	int N, input[3];
	cin >> N;

	for (int i = 0; i < 3; i++) {
		cin >> max_dp[i];
		min_dp[i] = max_dp[i];
	}

	int tmp_0, tmp_2;
	for (int i = 1; i < N; i++) {
		cin >> input[0] >> input[1] >> input[2];

		tmp_0 = max_dp[0]; tmp_2 = max_dp[2];
		max_dp[0] = max(max_dp[0], max_dp[1]) + input[0];
		max_dp[2] = max(max_dp[1], max_dp[2]) + input[2];
		max_dp[1] = max(max(tmp_0, max_dp[1]), tmp_2) + input[1];

		tmp_0 = min_dp[0]; tmp_2 = min_dp[2];
		min_dp[0] = min(min_dp[0], min_dp[1]) + input[0];
		min_dp[2] = min(min_dp[1], min_dp[2]) + input[2];
		min_dp[1] = min(min(tmp_0, min_dp[1]), tmp_2) + input[1];
	}

	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << ' ';
	cout << min(min(min_dp[0], min_dp[1]), min_dp[2]) << '\n';

	return 0;
}
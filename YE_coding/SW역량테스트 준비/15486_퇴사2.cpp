//백준 https://www.acmicpc.net/problem/15486
//퇴사 2
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, res = 0;
	cin >> N;

	vector<int> dp(N + 2, 0); // max값이 커서 dp로 풀기
	vector<pair<int, int>> sc(N + 2);

	for (int i = 1; i <= N; i++) {
		cin >> sc[i].first >> sc[i].second;
	}

	for (int i = 1; i <= N + 1; i++) {
		res = res > dp[i] ? res : dp[i]; // 최대값 갱신

		if (i + sc[i].first > N + 1) continue; // N+1일 초과하면 skip

		int next = i + sc[i].first; // i일 시작 상담 끝나는 날
		// 이전 설정값과 현 최대값 + next날 받을 돈 비교, 큰값으로 변경
		dp[next] = dp[next] > res + sc[i].second ? dp[next] : res + sc[i].second;
	}

	cout << res;
	return 0;
}
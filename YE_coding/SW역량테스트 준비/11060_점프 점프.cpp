//백준 https://www.acmicpc.net/problem/11060
//점프 점프
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 1000

using namespace std;

int arr[MAX], dp[MAX], N;

int miro(int x) {
	if (x >= N) return MAX;
	if (x == N - 1) return 0;

	int& res = dp[x];
	if (res != -1) return res;

	res = MAX;
	for (int i = 1; i <= arr[x]; i++) {
		res = min(res, miro(x + i) + 1);
	}

	return res;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	int res = miro(0);

	if (res == MAX) cout << -1;
	else cout << res;

	return 0;
}
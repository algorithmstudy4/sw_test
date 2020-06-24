//백준 https://www.acmicpc.net/problem/2230
//수 고르기
#include<iostream>
#include<algorithm>

using namespace std;

int N, M, arr[100000];
long long res = 2000000000;

int main() {
	int hi, lo, dis;

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	hi = 1; lo = 0;

	while (hi < N) {
		dis = arr[hi] - arr[lo];

		if (dis < M) hi++;
		else {
			res = res < dis ? res : dis;
			lo++;

			if (lo == hi) hi += 1;
		}
	}

	cout << res << '\n';
	return 0;
}

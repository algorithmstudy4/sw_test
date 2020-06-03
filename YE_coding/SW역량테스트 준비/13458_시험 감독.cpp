// 백준 https://www.acmicpc.net/problem/13458
// 시험 감독
#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, B, C;
	long long res = 0;
	cin >> N;

	vector<int> st(N);
	for (int i = 0; i < N; i++)
		cin >> st[i];
	cin >> B >> C;


	for (int i = 0; i < N; i++) {
		st[i] -= B;
		res += 1;

		if (st[i] < 0) continue;

		if (st[i] % C) res += st[i] / C + 1;
		else res += st[i] / C;
	}

	cout << res;
	return 0;
}
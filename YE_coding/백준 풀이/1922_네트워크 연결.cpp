//백준 https://www.acmicpc.net/problem/1922
//네트워크 연결
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, unf[1001], res;

struct edge {
	int s, e, val;

	bool operator< (const edge& eg) {
		return val < eg.val;
	}
};

int Find(int n) {
	if (unf[n] == n) return n;
	else return unf[n] = Find(unf[n]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int main() {
	int a, b, c;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) unf[i] = i;

	vector<edge> vec;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vec.push_back({ a, b, c });
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < M; i++) {
		a = Find(vec[i].s);
		b = Find(vec[i].e);
		if (a != b) {
			Union(a, b);
			res += vec[i].val;
		}
	}

	cout << res;
	return 0;
}
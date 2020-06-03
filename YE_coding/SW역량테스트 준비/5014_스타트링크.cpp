// 백준 https://www.acmicpc.net/problem/5014
// 스타트링크
#include<iostream>
#include<queue>

using namespace std;

int v[1000001];

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	for (int i = 1; i <= f; i++) v[i] = -1;

	queue<int> q;
	v[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now + u <= f && v[now + u] == -1) {
			v[now + u] = v[now] + 1;
			q.push(now + u);
		}

		if (now - d > 0 && v[now - d] == -1) {
			v[now - d] = v[now] + 1;
			q.push(now - d);
		}

		if (v[g] != -1) break;
	}

	if (v[g] == -1)
		cout << "use the stairs";
	else cout << v[g];

	return 0;
}
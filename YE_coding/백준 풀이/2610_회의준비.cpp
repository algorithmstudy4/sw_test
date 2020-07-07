//백준 https://www.acmicpc.net/problem/2610
//회의준비
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1000

using namespace std;

int parent[101];
bool group[101];

int Find(int n) {
	if (parent[n] == n) return n;
	else return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) parent[a] = b;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, MAX));

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = dist[b][a] = 1;
		Union(a, b);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	priority_queue<pair<int, int>> pq;
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == MAX) continue;
			tmp = max(tmp, dist[i][j]);
		}
		pq.push(make_pair(-tmp, i));
	}

	while (pq.size()) {
		int s = pq.top().first;
		int p = pq.top().second;
		pq.pop();

		if (!group[Find(p)]) {
			group[Find(p)] = true;
			res.push_back(p);
		}
	}

	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';

	return 0;
}
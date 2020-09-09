#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;

int N, M;
int map[10][10];
int dist[10][10];
bool real[11];
bool xo[11][11];
int dx[] = { 0,0,1,-1 }; int dy[] = { 1,-1,0,0 };
class Edge {
public:
	int node[2];
	int val;
	Edge(int x, int y, int val) {
		this->node[0] = x;
		this->node[1] = y;
		this->val = val;
	}
	bool operator < (Edge e) {
		return this->val < e.val;
	}
}; vector<Edge> edge;

void make_Is(int x, int y, int cnt) {
	queue<pair<int, int> > q;
	q.push({ x,y });
	dist[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (dist[nx][ny] == 0 && map[nx][ny] != 0) {
					dist[nx][ny] = cnt;
					q.push({ nx, ny });
				}
			}
		}
	}
}

void make_Bridege(int x, int y, int ct) {
	for (int i = 0; i < 4; i++) {
		int sx = x; int sy = y;
		int cnt = 0;
		for (int j = 0; j < 10; j++) {
			sx += dx[i]; sy += dy[i]; cnt++;
			if (sx < 0 || sx >= N || sy < 0 || sy >= M) break;
			if (dist[sx][sy] == ct) break;
			if (dist[sx][sy] != 0 && dist[sx][sy] != ct) {
				if (j > 1) {
					xo[ct][dist[sx][sy]] = true;
					//xo[dist[sx][sy]][ct] = true;
					edge.push_back({ ct,dist[sx][sy], j });
				}
				break;
			}
		}
	}
}

int getParent(int parent[], int a) {
	if (parent[a] == a) return a;//종료구문
	return parent[a] = getParent(parent, parent[a]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int ct = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] == 0 && map[i][j] != 0) {
				make_Is(i, j, ct);
				ct++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[i][j] != 0) {
				make_Bridege(i, j, dist[i][j]);
			}
		}
	}
	sort(edge.begin(), edge.end());
	int parent[11] = { 0 };
	for (int i = 1; i < ct; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < edge.size(); i++) {
		//cout << edge[i].node[0] << ' ' << edge[i].node[1] << ' ' << edge[i].val << '\n';
		if (!findParent(parent, edge[i].node[0], edge[i].node[1])) {
			sum += edge[i].val;
			unionParent(parent, edge[i].node[0], edge[i].node[1]);
		}
	}
	int ch = parent[1];
	for (int i = 2; i < ct; i++) {
		if (parent[i] == i) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << sum << '\n';
	return 0;
}

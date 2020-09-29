#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct camera {
	int first, second, value, dir;
};
int N, M, ans = 64;
int map[8][8];
bool tp[8][8];
int dy[] = { 1,0,-1,0 }, dx[] = { 0,-1,0,1 };
int Find(vector<camera> & vt) {
	memset(tp, false, sizeof(tp));
	for (int i = 0; i < vt.size(); i++) {
		camera cm = vt[i];
		tp[cm.first][cm.second] = true;
		int x, y;
		if (cm.value == 1) {
			x = cm.first;  y = cm.second;
			while (true) {
				x += dx[cm.dir]; y += dy[cm.dir];
				if (x < 0 || x >= N || y < 0 || y >= M) break;
				if (map[x][y] == 6) break;
				tp[x][y] = true;
			}
		}
		else if (cm.value == 2) {
			x = cm.first;  y = cm.second;
			if (cm.dir == 0 || cm.dir == 2) {
				int nx = cm.first; int ny = cm.second;
				while (true) {
					nx += dx[cm.dir % 4]; ny += dy[cm.dir % 4];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (map[nx][ny] == 6) break;
					tp[nx][ny] = true;
				}
				while (true) {
					nx += dx[(cm.dir + 2) % 4]; ny += dy[(cm.dir + 2) % 4];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (map[nx][ny] == 6) break;
					tp[nx][ny] = true;
				}
			}
			else {
				int nx = cm.first; int ny = cm.second;
				while (true) {
					nx += dx[cm.dir % 4]; ny += dy[cm.dir % 4];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (map[nx][ny] == 6) break;
					tp[nx][ny] = true;
				}
				while (true) {
					nx += dx[(cm.dir + 2) % 4]; ny += dy[(cm.dir + 2) % 4];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
					if (map[nx][ny] == 6) break;
					tp[nx][ny] = true;
				}
			}
		}
		else if (cm.value == 3) {
			int dir = cm.dir;
			for (int al = 0; al < 2; al++) {
				x = cm.first;  y = cm.second;
				dir %= 4;
				while (true) {
					x += dx[dir]; y += dy[dir];
					if (x < 0 || x >= N || y < 0 || y >= M) break;
					if (map[x][y] ==6) break;
					tp[x][y] = true;
				}
				dir += 1;
			}
		}
		else if (cm.value == 4) {
			int dor = cm.dir;
			for (int al = 0; al < 3; al++) {
				x = cm.first;  y = cm.second;
				dor %= 4;
				while (true) {
					x += dx[dor]; y += dy[dor];
					if (x < 0 || x >= N || y < 0 || y >= M) break;
					if (map[x][y] == 6) break;
					tp[x][y] = true;
				}
				dor += 1;
			}
		}
		else if (cm.value == 5) {
			for (int al = 0; al < 4; al++) {
				x = cm.first;  y = cm.second;
				while (true) {
					x += dx[al]; y += dy[al];
					if (x < 0 || x >= N || y < 0 || y >= M) break;
					if (map[x][y] == 6) break;
					tp[x][y] = true;
				}
			}
		}
	}
	int ret = 0;
	//cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && tp[i][j] == false) {
				ret += 1;
			}
		}
	}
	return ret;
}
void go(int cnt, vector<camera>&vt) {
	if (cnt == vt.size()) {
		int val = Find(vt);
		if (val < ans)
			ans = val;
		return;
	}
	if (vt[cnt].value == 5) {
		go(cnt + 1, vt);
	}
	else {
		for (int i = 0; i < 4; i++) {
			vt[cnt].dir = i;
			go(cnt + 1, vt);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	vector<camera> v;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){ 
			cin >> map[i][j]; 
			if (map[i][j] >= 1 && map[i][j] <= 5) 
				v.push_back({i, j, map[i][j], 0}); 
		}
	go(0, v);
	cout << ans << '\n';
}

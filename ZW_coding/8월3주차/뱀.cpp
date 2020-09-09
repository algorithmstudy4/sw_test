#include<iostream>
#include<vector>

using namespace std;

int n, L, cm;
bool map[101][101];
char cmd[10001];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
struct snake {
	int x, y, dir, time;
	bool bone = false;
	snake(int x, int y, int dir, int time, bool bone) {
		this->x = x;
		this->y = y;
		this->dir = dir;
		this->time = time;
		this->bone = bone;
	}
};
vector<snake> sn;
bool d[101][101];


void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == false)
				cout << 0 << ' ';
			else cout << 1 << ' ';
		}cout << '\n';
	}cout << '\n';
}

void game() {
	bool game = true;
	while (game) {
		int sx = sn[0].x; int sy = sn[0].y;
		if (map[sx][sy] == true) {
			sn.push_back({ sn[sn.size() - 1].x ,sn[sn.size() - 1].y ,sn[sn.size() - 1].dir, sn[sn.size() - 1].time - 1,true });
			map[sx][sy] = false;
		}
		for (int i = 0; i < sn.size(); i++) {
			int dir = sn[i].dir;
			int nx = sn[i].x + dx[dir]; int ny = sn[i].y + dy[dir];
			if (sn[i].bone == true) {
				sn[i].bone = false;
				sn[i].time++;
				d[sn[i].x][sn[i].y] = true;
				continue;
			}

			if (nx == 0 || nx == n + 1 || ny == 0 || ny == n + 1) {
				game = false;
				break;
			}

			if (i == 0 && d[nx][ny] == true) {
				game = false;
				break;
			}
			sn[i].time++;
			if (d[nx][ny] == false) {
				d[nx][ny] = true;
				d[sn[i].x][sn[i].y] = false;
			}
			else {
				game = false;
				break;
			}
			switch (cmd[sn[i].time]) {
			case 'L':
				sn[i].dir--;
				if (sn[i].dir < 0)
					sn[i].dir = 3;
				break;
			case 'D':
				sn[i].dir++;
				if (sn[i].dir > 3)
					sn[i].dir = 0;
				break;
			default:
				break;
			}
			sn[i].x = nx; sn[i].y = ny;
		}
		//print();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> L;
	for (int i = 0; i < L; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = true;
	}
	cin >> cm;
	for (int i = 0; i < cm; i++) {
		int x;
		char c;
		cin >> x >> c;
		cmd[x] = c;
	}
	sn.push_back({ 1,1,0,0,false });
	game();
	cout << sn[0].time + 1 << '\n';
	return 0;
}

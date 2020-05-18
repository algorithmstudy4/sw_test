//https://www.acmicpc.net/problem/13459
//13459.구슬탈출

#include<iostream>
#include<queue>

#define MAX 11
using namespace std;

struct info {
	int  rx, ry, bx, by, cnt;
};

int N, M;
char input[MAX][MAX];
bool check[10][10][10][10];
queue<info> infoq;

//왼쪽,오른쪽,위,아래
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

//입력받기
//# 장애물또는 벽, . 빈칸 , O 구멍 , R 빨간구슬, B 파란구슬
void getInput() {
	int rx, ry, bx, by, cnt;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input[i][j];
			if (input[i][j] == 'R') rx = i, ry = j;
			else if (input[i][j] == 'B')	bx = i, by = j;
		}
	}
	infoq.push({ rx,ry,bx,by,0 });
	check[rx][ry][bx][by] = true;
}

void move(int& x, int& y, int dx, int dy, int& cnt) {
	while (input[x + dx][y + dy] != '#' && input[x][y] != 'O') {
		y += dy;
		x += dx;
		cnt += 1;
	}
}

void BFS() {
	while (!infoq.empty()) {
		int ry = infoq.front().ry; int rx = infoq.front().rx;
		int by = infoq.front().by; int bx = infoq.front().bx;
		int cnt = infoq.front().cnt;
		infoq.pop();
		
		if (cnt >= 10)	break;
		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0;

			move(nrx, nry, dx[i], dy[i],rc);
			move(nbx, nby, dx[i], dy[i],bc);
			if (input[nbx][nby] == 'O') continue;
			if (input[nrx][nry] == 'O') {
				cout << "1" << endl;
				return;
			}
			if (nrx == nbx && nry == nby) {
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}
			if (check[nrx][nry][nbx][nby]) continue; // Already visited.
			check[nrx][nry][nbx][nby] = true;
			infoq.push({ nrx,nry, nbx, nby,  cnt + 1 });
		}
	}
	cout << "0" << endl;
}

int main() {
	getInput();
	BFS();
}
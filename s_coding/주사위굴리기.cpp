//주사위 굴리기
#include <iostream>
using namespace std;

int map[20 + 10][20 + 10];
int dr[5] = { 0,0,0,-1,1 }; //동:1 서:2 북:3 남:4
int dc[5] = { 0,1,-1,0,0 };
int dice[7] = { 0, };
int n, m, x, y, k, dir,nr,nc;

//주사위 굴리기
void right() {
	int tmp = dice[1]; //1번 top
	dice[1] = dice[4];
	dice[4] = dice[6];
	dice[6] = dice[3];
	dice[3] = tmp;
}
void left() {
	int tmp = dice[1];
	dice[1] = dice[3];
	dice[3] = dice[6];
	dice[6] = dice[4];
	dice[4] = tmp;
}
void up() {
	int tmp = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[6];
	dice[6] = dice[2];
	dice[2] = tmp;
}
void down() {
	int tmp = dice[1];
	dice[1] = dice[2];
	dice[2] = dice[6];
	dice[6] = dice[5];
	dice[5] = tmp;
}
void Solve() {
	//지도에서 좌표이동

	//고려하지 않았던 부분
	nr = x + dr[dir]; 
	nc = y + dc[dir];

	if (nr < 0 || nr >= n || nc < 0 || nc >= m)return;

	//return 되면 수행되면 안됨
	if (dir == 1) {
		right();
	}
	else if (dir == 2) {
		left();
	}
	else if (dir == 3) {
		up();
	}
	else if (dir == 4) {
		down();
	}

	if (map[nr][nc] != 0) {
		dice[6] = map[nr][nc]; //지도 숫자를 주사위 바닥면에
		map[nr][nc] = 0; //지도 0으로
	}
	else { //지도가 0이면

		map[nr][nc] = dice[6]; //주사위 바닥면이 지도에 복사
	}

	//헷갈렸던 부분
	x = nr;
	y = nc;
	cout << dice[1] << endl; //윗면 출력

}
void InputData() {

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) { 
	
		cin >> dir; //방향입력

		Solve();

	}
	
}
int main() {

	freopen("input.txt", "r", stdin);

	InputData();


	return 0;
}



//백준 https://www.acmicpc.net/problem/3190
//뱀
#include<iostream>
using namespace std;

int map[100 + 10][100 + 10]; 
int taildir[100 + 10][100 + 10]; //꼬리 방향 기록
char info[10000 + 10]; //방향전환정보

int dr[5] = { 0,-1,0,1,0 }; //시계방향 상:1 우:2 하:3 좌:4
int dc[5] = { 0, 0,1,0,-1 }; 
int N, K, L, X;

void InputData() {

	int r, c;
	char C;

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		map[r][c] = 2; //사과 표시
	}

	cin >> L; //방향전환횟수
	
	for (int i = 0; i < L; i++) {
		cin >> X >> C;

		info[X] = C;
	}

}
int turn(char ch,int dir) {

	if ( ch == 'L') { //왼쪽방향 회전
		//1234  
		//4123
		dir= (dir == 1) ? 4: dir - 1;
	}
	else if ( ch == 'D') { //오른쪽방향회전
		//1234
		//2341
		dir = (dir == 4) ? 1 : dir + 1;
	}

	return dir;
}
int Solve() {
	int time=0,dir=2; //처음 방향: 오른쪽 
	int hr, hc, tr, tc;

	hr = hc = tr = tc = 1; //뱀 출발위치
	map[hr][hc] = 1;

	while (1) {
		
		++time; //조심!!
		taildir[hr][hc] = dir;
		hr += dr[dir];
		hc += dc[dir];

		//종료조건: 벽에 부딪히거나 자신의 몸과 부딪히면 종료
		if (hr == 0 || hr > N || hc == 0 || hc > N || map[hr][hc] == 1)break;

		
		if (map[hr][hc] == 2) { //사과가 있으면
			map[hr][hc] = 1;
		}
		else { //사과가 없으면 이동
			map[tr][tc] = 0;  //꼬리 부분 지나감

			//저장된 꼬리방향에 따라 꼬리좌표이동

			//틀린 코드: tr의 값이 바뀌어서 꼬이게됨
			/*
				tr += dr[taildir[tr][tc]];
				tc += dc[taildir[tr][tc]];
			*/
			int d = taildir[tr][tc];
			tr += dr[d];
			tc += dc[d];

			map[hr][hc] = 1;//head이동
		}
		
		
		if (info[time] != 0) { //방향정보가 있음

			dir = turn(info[time],dir);

		}
	}


	return time;
}
int main() {
	int sol;

	freopen("input.txt", "r", stdin);

	InputData();

	sol=Solve();

	cout << sol;

	return 0;
}

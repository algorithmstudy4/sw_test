//백준 https://www.acmicpc.net/problem/3190
//뱀
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

struct Dir {
	int x, y;
};

Dir dir[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 좌표 이동

int N, K, L, sec;
int map[101][101];
/*
	-1 : 사과
	1 : 뱀
	0 : 빈 공간
*/

int main() {
	deque<pair<int, char>> cmd;
	deque<pair<int, int>> snake; // 앞뒤에서 push/pop 할 수 있도록 deque 사용
	snake.push_back({ 1, 1 });

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = -1;  // 사과 좌표
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char d;
		cin >> x >> d;
		cmd.push_back({ x, d }); // 시간 , 회전 방향
	}

	int index = 0;

	while (++sec) {
		int x = snake.back().first + dir[index].x;
		int y = snake.back().second + dir[index].y;

		if (x <= 0 || x > N || y <= 0 || y > N || map[x][y] == 1) break; // 좌표 이탈 or 몸 충돌

		if (map[x][y] != -1) { // 사과가 없으면 꼬리 빼기
			map[snake.front().first][snake.front().second] = 0;
			snake.pop_front();
		}
		snake.push_back({ x, y }); // 머리 전진
		map[x][y] = 1; // 뱀 좌표 표시

		if (!cmd.empty() && cmd.front().first == sec) { // 회전
			if (cmd.front().second == 'D') index = (index + 1) % 4;
			else index = (index + 3) % 4;

			cmd.pop_front();
		}
	}

	cout << sec;

	return 0;
}
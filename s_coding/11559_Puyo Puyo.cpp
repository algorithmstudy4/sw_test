#if 0
//Puyo Puyo
//https://www.acmicpc.net/problem/11559
#include <iostream>
#include <queue>
#include <cstring> //memset
#define r 12
#define c 6
using namespace std;

char map[r + 2][c + 2];
int visited[r + 2][c  + 2];
int dh[] = { -1,1,0,0 }; //상하좌우
int dw[] = { 0,0,-1,1 };


void fall() {
	for (int j = 0; j < c; j++) {
		for (int i = r - 1; i >= 0; i--) {
			if (map[i][j] == '.')continue;
			for (int k = r - 1; k >= i; k--) {
				if (map[k][j] == '.') {
					map[k][j] = map[i][j];
					map[i][j] = '.';
				}
			}
		}
	
	}

}
int BFS(int h,int w,char ch) { 
	//1. 초기화
	queue < pair < int, int> > q;
	vector <pair < int, int> > block;

	//2. 시작점 넣기
	q.push({ h,w });
	block.push_back({ h,w });
	visited[h][w] = 1;

	//3. 반복문
	while (!q.empty()) {
		pair < int, int > cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nh = cur.first + dh[i];
			int nw = cur.second + dw[i];
			
			if (nh < 0 || nh >= r || nw < 0 || nw >= c)continue;
			if (map[nh][nw] == ch && visited[nh][nw] == 0) {
				q.push({ nh,nw });
				block.push_back({ nh,nw });
				visited[nh][nw] = 1;
			}
		}
	
	}

	//4. 결과
	if (block.size() >= 4) {
		for (auto i : block) {
			map[i.first][i.second] = '.'; //뿌요되는 것 .로
		}
		return 1;
	}

	return 0;
}
bool bomb() {
	
	bool flag = false;

	memset(visited, 0, sizeof(visited));
	for (int i = r - 1; i >= 0; i--) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == '.' || visited[i][j] == 1) continue;
				
				if (BFS(i, j, map[i][j]) == 1) { 
					flag = true;
				}
		
		}
	}


	return flag;
}
void Solve() {
	int sol=0;

	while (bomb()) {
		fall();
		sol += 1;
	}
	cout << sol;
}
void InputData() {

	for (int i = 0; i < r; i++) {
		scanf("%s",&map[i][0]);
	}
}

int main() {


	freopen("input.txt", "r", stdin);
	InputData();
	Solve();
	
	return 0;
}
#endif

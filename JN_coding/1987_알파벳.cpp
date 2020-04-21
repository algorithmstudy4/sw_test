//https://www.acmicpc.net/problem/1987
//알파벳

#include<iostream>
#include<vector>
#include<memory.h>

#define RMAX 100
#define CMAX 21

using namespace std;

int R, C;
int input[RMAX][CMAX];
int visited[26];
int maxx = -1;

//왼쪽,오른쪽,위,아래 순서로 이동
int nexty[4] = { 0,0,-1,1 };
int nextx[4] = { -1,1,0,0 };

//이전에 지났던 알파벳인지 확인
bool checkAlpha(int yindex,int xindex) {
	if (visited[input[yindex][xindex]])	return true;
	return false;
}

void DFS(int yindex, int xindex, int result) {
	//범위 밖
	if (yindex < 0 || xindex < 0 || yindex >= R || xindex >= C)	return;
	//이미 지나친 알파벳
	if (checkAlpha(yindex,xindex)) {
		if (result > maxx)	maxx=result;
		return;
	}
	
	visited[input[yindex][xindex]] = 1;
	result++;

	for (int i = 0; i < 4; i++) {
		DFS(yindex + nexty[i], xindex + nextx[i], result);
	}

	visited[input[yindex][xindex]] = 0;
}

int main() {
	cin >> R >> C;

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char temp;
			cin >> temp;
			input[i][j] = temp - 65;
		}
	}

	DFS(0, 0, 0);
	cout << maxx;
}
//https://www.acmicpc.net/problem/16956
//16956 늑대와 양

#include<iostream>
#define MAX 501

using namespace std;

int R, C; //목장의 크기 = R*C
char input[MAX][MAX];

//좌,상,우,하 순서
int ysequence[4] = { 0,-1,0,1 };
int xsequence[4] = { -1,0,1,0 };
bool isPossible = true;	//울타리 생성 가능한지 확인하는 flag

//get Input
void getInput() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> input[i][j];
		}
	}
}

//상하좌우에 펜스
void makeFence(int y,int x) {
	for (int i = 0; i < 4; i++) {
		int yindex =y+ ysequence[i];
		int xindex =x+ xsequence[i];

		//out of index
		if (yindex < 0 || xindex < 0 || yindex >= R || xindex >= C) continue;
		
		if (input[yindex][xindex] == 'W')	isPossible = false;
		if (input[yindex][xindex]=='.')	input[yindex][xindex] = 'D';
	}
}

int main() {
	getInput();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (input[i][j] == 'S')	makeFence(i, j);
		}
	}

	if (isPossible == true) {
		cout << "1"<<endl;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << input[i][j];
			}
			cout << endl;
		}
	}else {
		cout << "0";
	}
}
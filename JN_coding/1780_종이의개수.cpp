//https://www.acmicpc.net/problem/1780
//종이의개수

#include<iostream>
#include<vector>
using namespace std;

int minus_one = 0, zero = 0, one = 0;
vector<vector<int > >paper;

int check(int xstart, int ystart, int size) {
	int num = paper[xstart][ystart];
	for (int i = 0; i <size; i++) {
		for (int j = 0; j < size; j++) {
			if (paper[xstart+i][ystart+j] != num)	return -10;
		}
	}

	return num;
}

void cutting(int xstart,int ystart,int size) {
	int checking = check(xstart,ystart,size);
	if (checking == -10) {
		int gap = size / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cutting(xstart+(gap*i),ystart+(gap*j),gap);
			}
		}
	}
	else {
		if (checking == 0)	zero++;
		else if (checking == 1)	one++;
		else if (checking == -1)	minus_one++;
	}
}


int main() {
	int N;
	cin >> N;

	paper.resize(N);
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			paper[i].push_back(input);
		}
	}
	cutting(0,0,N);

	cout << minus_one << endl << zero<<endl<<one;
}
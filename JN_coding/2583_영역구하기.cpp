//https://www.acmicpc.net/problem/2583
//영역 구하기

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> squareSize;
int input[101][101];
int M, N, K;
int sum;

void getSquare(int y, int x) {
	//인덱스 범위 확인
	if (y >= N || x >= M || x < 0 ||y<0)	return;
	
	//이미 확인했거나 칠해져있는 곳
	if (input[y][x]==1)	return;
	
	sum += 1;
	input[y][x] = 1;

	getSquare(y - 1, x);
	getSquare(y + 1, x);
	getSquare(y, x - 1);
	getSquare(y, x + 1);

}

int main() {
	cin >> N >> M >> K;

	memset(input, 0, sizeof(input));

	//칠해져있는 영역 : 1
	int leftx, lefty, rightx, righty;
	for (int i = 0; i < K; i++) {
		
		cin >> leftx >> lefty >> rightx >> righty;
		for (int j = leftx; j < rightx;j++) {
			for (int k = lefty; k < righty; k++) {
				input[k][j] = 1;
			}
		}
	}

	//영역의 합 더해서 squareSize에 넣기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum = 0;
			getSquare(i, j);
			if (sum != 0)	squareSize.push_back(sum);
		}
	}

	sort(squareSize.begin(), squareSize.end());	//오름차순 정렬
	cout << squareSize.size() << endl;
	for (int i = 0; i < squareSize.size(); i++) {
		cout << squareSize[i] << " ";
	}


}
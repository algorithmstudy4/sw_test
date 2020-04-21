//https://www.acmicpc.net/problem/2580
//스도쿠

#include<iostream>
#include<memory.h>

using namespace std;

int input[10][10];

int sudoRow[10][10];
int sudoCol[10][10];
int sudoSquare[10][10];

int makeSquareIndex(int yindex, int xindex) {
	return (yindex / 3) * 3 + (xindex / 3);
}

void sudo(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << input[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}

	int yindex = cnt / 9;
	int xindex = cnt % 9;

	if (input[yindex][xindex])	sudo(cnt + 1);
	else {
		for (int i = 1; i < 10; i++) {
			if (!sudoRow[yindex][i] && !sudoCol[xindex][i] && !sudoSquare[makeSquareIndex(yindex, xindex)][i]) {
				input[yindex][xindex] = i;
				sudoRow[yindex][i] = true;
				sudoCol[xindex][i] = true;
				sudoSquare[makeSquareIndex(yindex, xindex)][i] = true;
				sudo(cnt + 1);
				input[yindex][xindex] = 0;
				sudoRow[yindex][i] = false;
				sudoCol[xindex][i] = false;
				sudoSquare[makeSquareIndex(yindex, xindex)][i] = false;

			}
		}
	}

}

int main() {
	memset(sudoCol, 0, sizeof(sudoCol));
	memset(sudoRow, 0, sizeof(sudoRow));
	memset(sudoSquare, 0, sizeof(sudoSquare));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> input[i][j];
			if (input[i][j]) {
				sudoRow[i][input[i][j]]=1;
				sudoCol[j][input[i][j]] = 1;
				sudoSquare[makeSquareIndex(i,j)][input[i][j]] = 1;
			}
		}
	}

	sudo(0);
}
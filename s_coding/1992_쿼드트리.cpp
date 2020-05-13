//1992 쿼드 트리
//https://www.acmicpc.net/problem/1992
#include <iostream>
#include <string>
using namespace std;

int arr[64][64];

//1.현재 구간에 있는 구간들이 0 으로만 또는 1로만 이루어져 있으면 해당숫자 출력
//2.1번 조건이 성립하지 않으면 ( 출력하고 2->1->4->3 사분면 순서로 구간을 잘라 재귀호출 후 )출력
//3.기저사례는 구간의 크기가 1일 경우 , 구간의 크기가 1이면 해당 숫자 출력

void compress(int n,int y,int x){ //(y,x):start point
	
	bool zero = true, one = true;

	//기저사례: 해당 숫자 출력 
	if (n == 1) {
		cout << arr[y][x];
		return;
	}

	for (int i = y; i < y + n; i++) { //구간내에서
		for (int j = x; j < x + n; j++) {
			if (arr[i][j] == 1) { //구간내에서 1이 하나라도 있으면
				zero = false; //0은 false
			}else { //구간 내에서 0이 하나라도 있으면
				one = false; //1은 false
			}
		}
	}
	
	if (zero) { //zero true면 구간내에서 zero밖에 없는 것
		cout << "0";
	}
	else if (one) { //one이 true면 구간 내에서 one밖에 없는것
		cout << "1";
	}
	else { //0으로만 ,1로만 , 이루어져 있지 않다면 재귀 통해서 구간 반으로 
		cout << "(";
		compress(n / 2, y, x); //2사분면
		compress(n / 2, y, x+n/2); //1사분면
		compress(n / 2, y+n/2, x); //3사분면
		compress(n / 2, y + n / 2, x + n / 2); //4사분면
		cout << ")";
	}
	return;
}
int main() {

	int size;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> size;

	bool zero = true, one = true;

	for (int i = 0; i < size; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < size; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	
	compress(size, 0, 0);
	cout << endl;

	return 0;
}

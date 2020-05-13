//색종이만들기
//https://www.acmicpc.net/problem/2630
#include <iostream>
using namespace std;

int paper[128][128];
int white, blue;
void divide(int x1, int y1, int x2, int y2) {
	int cntBlue = 0; //영역내의 1의 개수
	int cntWhite = 0; //영역내의 0의 개수

	//왼쪽상단지점, 출발점은 (x1,y1) 오른쪽 하단지점 끝점(x2,y2)
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			if (paper[i][j] == 1)cntBlue++;
			else cntWhite++;
		}
	}

	//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<endl;
	//cout<<cntBlue<<" "<<cntWhite<<endl;

	//영역내에서 color가 같은 색깔이면 paper추가
	//아니라면 4분할해서 같은 색깔일때까지 반복 
	if (cntBlue == 0) {
		white++;
	}else if (cntWhite == 0) {
		blue++;
	}else {
		divide(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2); //1
		divide((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2); //2
		divide(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2); //3
		divide((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2); //4
	}
}
int main() {
	
	int size;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin>>paper[i][j];
		}
	}
	divide(0, 0, size - 1, size - 1);
	cout << white << endl << blue;

}

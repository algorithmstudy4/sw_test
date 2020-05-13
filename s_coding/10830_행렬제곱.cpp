//행렬제곱
//https://www.acmicpc.net/problem/10830
#include <iostream>
using namespace std;
long long a[6][6], ans[6][6], c[6][6], n, b;
void cal(long long a[6][6], long long b[6][6]){

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			c[i][j] = 0;
			for (int k = 1; k <= n; k++) {

				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;  //문제에서 수가 커질 수 있으니 A^B의 각 원소를 1000으로 나눈 나머지 출력
		}
	}
	for (int i = 1; i <= n; i++) //계산된 값 행렬 A에 다시 넣기 
		for (int j = 1; j <= n; j++) 
			a[i][j] = c[i][j];

}
int main() {
	cin >> n >> b; //행렬의 크기 n*n , b제곱

	for (int i = 1; i <= n; i++){

		for (int j = 1; j <= n; j++){

			cin >> a[i][j];

		}
		ans[i][i] = 1;
	}

	while (b > 0){

		if (b % 2 == 1){//지수 홀수일 경우 행렬 하나 먼저 계산, A^5= A*A^2*A^2 
			cal(ans, a);
		}
		cal(a, a);
		b /= 2; //짝수 몫 만들기 
		//cout << b<<endl;
	}
	for (int i = 1; i <= n; i++){

		for (int j = 1; j <= n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout <<endl;
	}
	return 0;
}


//피보나치수3
//https://www.acmicpc.net/problem/2749
#include<iostream>
using namespace std;
long long pisano[1500050];
int INF = 1000000;

void fibonacci() {
	pisano[0] = 0;
	pisano[1] = 1;
	for (int i = 0; i < 1500000; i++) { //주기 만큼 반복해서 저장 
		pisano[i + 2] = (pisano[i + 1] + pisano[i]) % INF; //피보나치 수를 1000000으로 나눈 나머지
		//cout << pisano[i + 2] << endl;
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;
	fibonacci();
	cout << pisano[n % 1500000] << endl;

	return 0;
}

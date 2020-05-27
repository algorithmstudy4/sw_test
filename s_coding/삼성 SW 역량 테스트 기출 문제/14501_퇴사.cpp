#if 01
//퇴사
//https://www.acmicpc.net/problem/14501
#include <iostream>
using namespace std;

int N,sol;
int t[15 + 1]; //일하는데 걸리는 기간
int p[15 + 1]; //일하면 받는 돈

void Solve(int day,int total) {

	if (day == N + 1) { //ex) 8일이되면 , 계산조건 
		if (sol < total)sol = total;
		return;
	}
	if (day > N + 1)return; //ex) 8일보다 커지면 종료 , 종료조건
	//if(day + t[day] <= N+ 1)
	//if(day + 1 <= N + 1)

	//상담하는 경우
	if (day + t[day] <= N + 1)Solve(day + t[day], total + p[day]);

	//상담하지 않는 경우
	if (day + 1 <= N + 1)Solve(day + 1, total);
}
void InputData() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}
}
int main() {

	freopen("input.txt", "r", stdin);
	InputData();
	Solve(1,0);

	printf("%d", sol);
	return 0;
}
#endif

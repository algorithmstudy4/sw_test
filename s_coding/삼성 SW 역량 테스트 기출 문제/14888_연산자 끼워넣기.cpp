#if 01
//연산자
//https://www.acmicpc.net/problem/14888
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[11];
int op[4];
int min_res = 0x7fffffff, max_res = min_res * -1;

void DFS(int result,int cnt) { //연산자의 조합

	if (cnt == N - 1) {
		max_res = max(max_res, result);
		min_res = min(min_res, result);
		return;
	}

	for (int i = 0; i < 4; i++) {

		if (op[i] != 0) { //남아있는 연산자가 있으면
			op[i]--;

			if (i == 0) {
				DFS(result + arr[cnt + 1], cnt + 1);
			}
			else if (i == 1) {
				DFS(result - arr[cnt + 1], cnt + 1);
			}
			else if (i == 2) {
				DFS(result * arr[cnt + 1], cnt + 1);
			}
			else if (i == 3) {
				DFS(result / arr[cnt + 1], cnt + 1);
			}
			op[i]++;
		}


	
	}

}
void InputData() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}
}
int main() {

	freopen("input.txt", "r", stdin);
	InputData();
	DFS(arr[0],0);

	printf("%d\n%d", max_res, min_res);

	return 0;
}

#endif

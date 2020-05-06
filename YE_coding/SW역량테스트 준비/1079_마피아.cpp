// 백준 https://www.acmicpc.net/problem/1079
// 마피아
#include<iostream>
#include<vector>
#define MAX 20

using namespace std;

int N, eun, score[MAX], R[MAX][MAX], res;
bool dead[MAX];

void mafia(int night, int num) {
	if (dead[eun] || num == 1) {
		res = night > res ? night : res;
		return;
	}

	if(num % 2 == 0){
		for (int i = 0; i < N; i++) {
			if (i == eun || dead[i]) continue;

			dead[i] = true;
			for (int j = 0; j < N; j++) {
				if (dead[j]) continue;
				score[j] += R[i][j];
			}

			mafia(night + 1, num - 1);

			for (int j = 0; j < N; j++) {
				if (dead[j]) continue; 
				score[j] -= R[i][j];
			}
			dead[i] = false;
		}
	}
	else {
		int idx = 0, tmp = 0;
		for (int i = 0; i < N; i++) {
			if (dead[i]) continue;

			if (score[i] > tmp) {
				tmp = score[i];
				idx = i;
			}
		}

		dead[idx] = true;
		mafia(night, num - 1);
		dead[idx] = false;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> score[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> R[i][j];
		}
	}
	cin >> eun;

	mafia(0, N);
	cout << res;

	return 0;
}
#if 0
//스타트와 링크
//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <algorithm>

#define MAXN (20)
using namespace std;

int N;
int map[MAXN + 2][MAXN + 2];
int pick[MAXN]; //팀원 뽑기
int start[10], link[10];
int sol = 0x7fffffff;
void Solve() {
	int scnt=0, lcnt = 0;

	//start (1,3,6) link에는 (2,4,5)들어감
	for (int i = 0; i < N; i++) {
		if (pick[i] == 1) { //뽑힌것 
			start[scnt++] =i;
		}
		else { //안뽑힌 것  
			link[lcnt++] =i;
		}
	}

	//팀점수계산
	int startscore = 0, linkscore = 0;
	for (int i = 0; i < N / 2; i++) { //순열 : 중복없음 순서있음 
		for (int j = i + 1; j < N / 2; j++) {
			startscore += (map[start[i]][start[j]] + map[start[j]][start[i]]);
			linkscore  += (map[link[i]][link[j]] + map[link[j]][link[i]]);
		}
	}

	sol = min(sol, abs(startscore - linkscore));

}
void DFS(int idx,int cnt) { //n개중 n/2개 뽑기 
	
	if (cnt == (N / 2)) {
	
		Solve();
		return;
	}

	for (int i = idx; i< N; i++) {
		pick[i] = 1;
		DFS(i + 1, cnt + 1);
		pick[i] = 0;
	}

}
void InputData() {
	
	scanf("%d", &N);
	for (int i = 0; i <  N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

}
int main() {

	freopen("input.txt", "r", stdin);
	InputData();
	DFS(0,0);

	printf("%d", sol);

	return 0;
}
#endif

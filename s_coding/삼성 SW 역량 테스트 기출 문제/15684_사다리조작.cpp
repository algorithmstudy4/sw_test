#if 01
//사다리 조작
//https://www.acmicpc.net/problem/15684
#include <iostream>
using namespace std;

int N, M, H;//세로선 개수, 가로선 개수(연결다리 개수), 세로선마다 가로선 놓을 수 있는 위치 개수
int map[30 + 2][10 + 2];
int sol = 4; //답은 -1 0 1 2 3 가능하므로

bool check() {//i번째 세로선이 i번이 되는지 체크 

	for (int i = 1; i <= N; i++) { // 양옆
		int goal = i; //목표가 i번째, 시작점 저장 
		//한 줄에서 시작

		//밑으로 내려가면서 
		for (int j = 1; j <= H; j++) { //갈 수있는 방향 2가지 오른쪽 왼쪽 
			if (map[j][goal] == 1) { //그 위치가 1이면 오른쪽
				goal++;
			}
			else if (map[j][goal - 1] == 1) { //왼쪽으로 이동 
				goal--;
			}
		}

		if (goal != i)return false; //i번째에 도달 못하면 
	}

	return true;
}
void DFS(int cnt, int h, int w) {
	if (cnt >= sol)return; // 답이 나올수 없는 경우의 수 
	if (check()) { //i번째 세로선이 i번이 되는지 체크
		sol = cnt;
		return;
	}
	if (cnt == 3)return; //최대가 3개 

	//연결다리 추가하기 
	for (int i = h; i <= H; i++) { //세로
		for (int j = w; j < N; j++) { //가로
			//양옆으로 인접하면 안됨
			if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) {
				map[i][j] = 1;
				DFS(cnt + 1, i, j);
				map[i][j] = 0;
			}
		}
		w = 1; //dfs돌면서 w가 바뀜, 다시 처음부터 돌아야함
	
	}
}
int main() {
	int a, b;

	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = 1; //연결다리 체크 
	}

	DFS(0, 1, 1);

	if (sol > 3) sol =-1;
	printf("%d", sol);

	return 0;
}
#endif

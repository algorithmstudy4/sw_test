//백준 https://www.acmicpc.net/problem/2422
//한윤정이 이탈리아에 가서 아이스크림을 사먹는데
#include<iostream>
#include<vector>

using namespace std;

int N, cnt;
int ice[201], res[3];
bool taste[201][201];

void DFS(int c, int L) {
	if (L == 3) {
		if (!taste[res[0]][res[1]] && !taste[res[1]][res[2]] && !taste[res[0]][res[2]])
			cnt++;
		return;
	}
	if (c > N) return;

	res[L] = c;
	DFS(c + 1, L + 1);
	DFS(c + 1, L);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		taste[a][b] = taste[b][a] = true;
	}

	DFS(1, 0);
	cout << cnt;
	return 0;
}
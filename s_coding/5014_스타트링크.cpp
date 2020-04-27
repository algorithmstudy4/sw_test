#if 01
//스타트링크 
// https://www.acmicpc.net/problem/5014

#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;

int visited[MAX + 10];
int F,S,G,U,D;
queue<int> q;

int BFS() {
	q.push(S);
	visited[S] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == G)return visited[cur] - 1;

		if (cur + U <= F && visited[cur + U] == 0) { //UP
			q.push(cur + U);
			visited[cur + U] = visited[cur] + 1;
		}
		if (cur - D >= 1 && visited[cur - D] == 0) { //DOWN
			q.push(cur - D);
			visited[cur - D] = visited[cur] + 1;
		}



	}
	return -1;
}
void InputData() {
	cin >> F >> S >> G >> U >> D;
}
int main() {
	freopen("input.txt", "r", stdin);

	int sol;
	InputData();
	sol = BFS();
	if (sol == -1) cout << "use the stairs";
	else cout << sol;

	return 0;
}

#endif

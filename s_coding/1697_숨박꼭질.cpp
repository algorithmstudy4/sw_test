#if 01
//숨박꼭질
// https://www.acmicpc.net/problem/1697

#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int N, K;
int visited[MAX + 10];
queue<int> q;

int BFS() {
	q.push(N);
	visited[N] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == K)return visited[cur]-1;

		if (cur - 1 >= 0 && visited[cur - 1] == 0) { //x-1
			q.push(cur-1);
			visited[cur-1] = visited[cur] + 1;
		}
		if (cur + 1 <= MAX && visited[cur + 1] == 0) { //x+1
			q.push(cur+1);
			visited[cur + 1] = visited[cur] + 1;
		}
		if (cur*2 <= MAX && visited[cur * 2] == 0) {//2*x
			q.push(cur*2);
			visited[cur *2] = visited[cur] + 1;
		}
		
		
	
	}

}
void InputData() {
	cin >> N >> K;
}
int main() {
	int sol;
	InputData();
	sol = BFS();
	cout << sol;
	return 0;
}

#endif

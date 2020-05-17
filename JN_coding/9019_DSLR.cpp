//https://www.acmicpc.net/problem/9019
//DSLR

#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#define MAX 10000

using namespace std;
int Start, End;
bool visited[MAX];

string BFS() {
	queue<pair<int, string>> bfs;
	memset(visited, false, sizeof(visited));

	bfs.push(make_pair(Start, ""));
	visited[Start] = true;

	while (!bfs.empty()) {
		int num = bfs.front().first;
		string s = bfs.front().second;


		bfs.pop();

		//Start==End
		if (num == End)	return s;

		int temp = num * 2;
		if (temp > 9999)	temp = temp % 10000;
		if (!visited[temp]) {
			visited[temp] = true;
			bfs.push(make_pair(temp, s + "D"));
		}

		temp = num - 1;
		if (temp < 0)	temp = 9999;
		if (!visited[temp]) {
			visited[temp] = true;
			bfs.push(make_pair(temp, s + "S"));
		}

		temp = (num % 1000) * 10 + (num / 1000);
		if (!visited[temp]) {
			visited[temp] = true;
			bfs.push(make_pair(temp, s + "L"));
		}

		temp = (num % 10) * 1000 + (num / 10);
		if (!visited[temp]) {
			visited[temp] = true;
			bfs.push(make_pair(temp, s + "R"));
		}
	}
}

int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		cin >> Start >> End;
		cout << BFS() << endl;
	}
}
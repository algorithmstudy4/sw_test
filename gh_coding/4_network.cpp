#include <string>
#include <vector>
#include<iostream>
// 프로그래머스 네트워크
// dfs 3단계
//https://programmers.co.kr/learn/courses/30/lessons/43162
using namespace std;
vector<int> check;
void dfs(int next, vector<vector<int>> computers) {
	check[next] = 1;
 	for (int i = 0; i < computers[next].size(); i++) {
		if (i == next) continue;
		
		if (computers[next][i] == 1 && check[i] == 0) {
			dfs(i, computers);
		}
	}

}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	check.assign(computers[0].size(), 0);
	for (int i = 0; i < computers[0].size(); i++) {
	
		if (check[i] == 0) {
			answer += 1;
			dfs(i, computers);
		}
	
	}
	return answer;
}
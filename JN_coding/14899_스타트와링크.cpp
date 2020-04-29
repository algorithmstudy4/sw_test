//https://www.acmicpc.net/problem/14889
//14899 스타트와 링크

#include <iostream>
#include<vector>
#define NSIZE 21

using namespace std;

int N;
int input[NSIZE][NSIZE];
int minn=99999;

bool visited[NSIZE] = { false };
vector<int> team;

int start_sum = 0, link_sum = 0;

//점수 차이
int check_min() {
	int teamindex[NSIZE] = { 0 };
	vector<int> start_team;
	vector<int> link_team;

	for (int i = 0; i < N / 2; i++) {
		teamindex[team[i]] = 1;
	}

	for (int i = 0; i < N; i++) {
		if (teamindex[i] == 1)	start_team.push_back(i);
		else link_team.push_back(i);
	}

	start_sum = 0; link_sum = 0;
	//start_sum
	for (int i = 0; i < N / 2; i++) {
		for (int j = i; j < N / 2; j++) {
			start_sum += input[start_team[i]][start_team[j]];
			start_sum += input[start_team[j]][start_team[i]];

			link_sum += input[link_team[i]][link_team[j]];
			link_sum += input[link_team[j]][link_team[i]];
		}
	}

	return abs(link_sum - start_sum);
}

//조합 만들기
void make_team(int index) {
	if (team.size() == N / 2) {
		int result = check_min();
		if (result < minn)	minn = result;
		return;
	}

	int	smallest =(team.empty() ? 0 : team.back()+1);

	for(int i=smallest;i<N;i++){
		if(visited[i])	continue;
		visited[i] = true;
		team.push_back(i);
		make_team(i);
		visited[i] = false;
		team.pop_back();
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input[i][j];
		}
	}

	make_team(0);
	cout << minn;
}
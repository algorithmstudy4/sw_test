#if 0
//치킨배달
//https://www.acmicpc.net/problem/15686
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 50
using namespace std;

int map[MAX][MAX];
int N, M;
int sol = 0x7fffffff;

struct pos {
	int h;
	int w;
};
vector<pos> home, chicken,selected;


void DFS(int idx,int cnt ) { //조합 재귀 

	//if (n > chicken.size())return; //종료조건 : 치킨집 개수보다 클 때
	if (cnt ==	M) { 
		int sum=0;

		for (int i = 0; i < (int)home.size(); i++) {
			int d = 99999999;
		
			for (int j = 0; j < (int)selected.size(); j++) {
			//for (auto j : selected) {
				d = min(d, abs(home[i].h - selected[j].h) + abs(home[i].w - selected[j].w));
			}
			sum += d;

		}
		sol = min(sol, sum);
		return;
	}

	for (int i = idx; i < (int)chicken.size(); i++) {
		//치킨집 선택 
		selected.push_back(chicken[i]);
		DFS(i + 1, cnt + 1);
		selected.pop_back();
	}


}
void InputData() {
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1) home.push_back({ i,j }); //집
			else if (tmp == 2) chicken.push_back({ i,j }); //치킨
		}
	}


}
int main() {

	freopen("input.txt", "r", stdin);

	InputData();
	DFS(0,0);
	printf("%d", sol);

}
#endif

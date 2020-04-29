//백준 https://www.acmicpc.net/problem/15686
//치킨 배달
#include<iostream>
#include<vector>

using namespace std;

int N, M, arr[50][50], ch[13], res = 2147000000;
vector<pair<int, int>> house, chick;

void DFS(int L, int idx) {
	if (L == M) {
		int dis, sum = 0;
		for (int i = 0; i < house.size(); i++) {
			dis = 2147000000;
			int nx = house[i].first;
			int ny = house[i].second;

			for (int j = 0; j < M; j++) {
				int temp = abs(nx - chick[ch[j]].first) + abs(ny - chick[ch[j]].second);
				dis = dis < temp ? dis : temp;
			}
			sum += dis;
		}
		res = res < sum ? res : sum;
		return;
	}
	if (idx == chick.size()) return;

	ch[L] = idx;
	DFS(L + 1, idx + 1);
	DFS(L, idx + 1);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) house.push_back(make_pair(i, j));
			else if (arr[i][j] == 2) chick.push_back(make_pair(i, j));
		}
	}

	DFS(0, 0);
	cout << res;
	return 0;
}
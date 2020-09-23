#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int r, c, k, H, W;
int map[101][101];
bool ending = false;

bool oper1(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	else {
		return p1.second < p2.second;
	}
}

bool oper2(pair<int, int> p2, pair<int, int> p1) {
	return p1.second < p2.second;
}

void R() {
	int maxx = W;
	for (int i = 0; i < H; i++) {
		vector<pair<int, int> > v;
		int maxso = 0;
		for (int j = 0; j < W; j++) {
			bool so = false;
			for (int k = 0; k < v.size(); k++) {
				if (v[k].first == map[i][j] && map[i][j] != 0) {
					v[k].second++;
					so = true;
					break;
				}
			}
			if (!so && map[i][j] != 0)
				v.push_back({ map[i][j],1 });
			if (maxso < map[i][j]) maxso = map[i][j];
		}
		if (v.size() > 50) {
			ending = true;
			return;
		}
		sort(v.begin(), v.end(), oper1);
		if (v.size() * 2 > maxx) maxx = v.size() * 2;
		for (int j = 0; j < W; j++) {
			map[i][j] = 0;
		}
		int idx = 0;
		for (int j = 0; j < v.size(); j++) {
			map[i][idx++] = v[j].first;
			map[i][idx++] = v[j].second;
		}
	}
	W = maxx;
}

void C() {
	int maxx = H;
	for (int i = 0; i < W; i++) {
		vector<pair<int, int> > v;
		int maxso = 0;
		for (int j = 0; j < H; j++) {
			bool so = false;
			for (int k = 0; k < v.size(); k++) {
				if (v[k].first == map[j][i] && map[j][i] != 0) {
					v[k].second++;
					so = true;
					break;
				}
			}if (!so && map[j][i] != 0)
				v.push_back({ map[j][i],1 });
			if (maxso < map[j][i]) maxso = map[j][i];
		}
		if (v.size() > 50) {
			ending = true;
			return;
		}
		sort(v.begin(), v.end(), oper1);
		if (v.size() * 2 > maxx) maxx = v.size() * 2;
		for (int j = 0; j < H; j++) {
			map[j][i] = 0;
		}
		int idx = 0;
		for (int j = 0; j < v.size(); j++) {
			map[idx++][i] = v[j].first;
			map[idx++][i] = v[j].second;
		}
	}
	H = maxx;
}

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}H = 3; W = 3;
	int tim = 0;
	while (!ending) {
		if (map[r - 1][c - 1] == k) {
			break;
		}

		if (H >= W)
			R();
		else C();
		tim++;
		if (tim > 100) break;
	}
	if (tim > 100)
		printf("-1\n");
	else
		printf("%d\n", tim);
	return 0;
}

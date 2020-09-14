#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#define endl '\n'
using namespace std;
int N, M, K;
char map[1000][1000];
string dojang[500][500];
pair<int, int> cnt[500];
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}cout << endl;
	}

}
void make_map(int num,int x, int y) {
	for (int i = 0; i < cnt[num-1].first; i++) {
		for (int j = 0; j < cnt[num-1].second; j++) {
			if (x + i < 0 || x + i >= N || y + i < 0 || y + j >= M) break;
			map[x + i][y + j] = dojang[num-1][i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cin >> K;
	int H = 0;  int W = 0;
	string tp = "";
	for (int i = 0; i < K; i++) {
		cin >> H >> W;
		cnt[i].first = H; cnt[i].second = W;
		for (int j = 0; j < H; j++)
				cin >> dojang[i][j];
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = '.';
	
	int commandd;
	cin >> commandd;
	int x, y, c;
	for (int i = 0; i < commandd; i++) {
		cin >> c >> x >> y;
		make_map(c, x, y);
	}
	print();
}

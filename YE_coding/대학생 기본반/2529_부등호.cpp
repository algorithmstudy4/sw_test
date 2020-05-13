// 백준 https://www.acmicpc.net/problem/2529
// 부등호
#include<iostream>
#include<vector>
#include<string>
#define MAX 9876543210

using namespace std;

int k, res[10];
long long  max_v, min_v = MAX;
char op[9];
bool check[10];

void DFS(int L) {
	if (L == k + 1) {
		long long tmp = 0;

		for (int i = 0; i < k; i++) {
			if (op[i] == '>' && res[i] < res[i + 1]) return;
			else if (op[i] == '<' && res[i] > res[i + 1]) return;

			tmp = tmp * 10 + res[i];
		}
		tmp = tmp * 10 + res[k];

		min_v = min_v < tmp ? min_v : tmp;
		max_v = max_v > tmp ? max_v : tmp;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!check[i]) {
			check[i] = true;
			res[L] = i;
			DFS(L + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> op[i];

	DFS(0);
	string max_s = to_string(max_v);
	string min_s = to_string(min_v);

	while (min_s.length() < k + 1) min_s = '0' + min_s;

	cout << max_s << '\n' << min_s;
	return 0;
}
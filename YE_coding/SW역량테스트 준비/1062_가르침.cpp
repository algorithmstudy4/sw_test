//백준 https://www.acmicpc.net/problem/1062
//가르침
#include<iostream>
#include<string>

using namespace std;

int N, K, ans;
string word[50];
bool flag, visit[26];

void DFS(int L, int idx) {
	if (L == K - 5) {
		int sum = 0;

		for (int i = 0; i < N; i++) {
			flag = true;
			string str = word[i];

			for (int j = 0; j < str.length(); j++) {
				if (!visit[str[j] - 'a']) {
					flag = false;
					break;
				}
			}
			if (flag) sum++;
		}

		ans = ans > sum ? ans : sum;
		return;
	}
	if (idx >= 26) return;

	if (!visit[idx]) {
		visit[idx] = true;
		DFS(L + 1, idx + 1);
		visit[idx] = false;
	}
	DFS(L, idx + 1);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}

	visit[0] = visit['n' - 'a'] = visit['t' - 'a'] = visit['i' - 'a'] = visit['c' - 'a'] = true;
	DFS(0, 0);

	cout << ans;
	return 0;
}
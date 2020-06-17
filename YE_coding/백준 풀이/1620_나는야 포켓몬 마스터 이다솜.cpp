//백준 https://www.acmicpc.net/problem/1620
//나는야 포켓몬 마스터 이다솜
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 100000 + 1

using namespace std;

int N, M;
vector<string> num;
vector<pair<string, int>> name;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	num.resize(N + 1); name.resize(N + 1);

	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;

		num[i] = s;
		name[i] = make_pair(s, i);
	}

	sort(name.begin(), name.end());

	while (M--) {
		cin >> s;

		if (s[0] >= '0' && s[0] <= '9') cout << num[atoi(s.c_str())] << '\n';
		else {
			int left = 0, right = N;

			while (left <= right) {
				int mid = (left + right) / 2;

				if (name[mid].first == s) {
					cout << name[mid].second << '\n';
					break;
				}

				if (name[mid].first > s) right = mid;
				else left = mid + 1;
			}
		}
	}

	return 0;
}

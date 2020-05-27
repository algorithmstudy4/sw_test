// 백준 https://www.acmicpc.net/problem/1747
// 소수&팰린드롬
#include<iostream>
#include<string>
#include<cstring>
#define MAX 1003001 + 1

using namespace std;

int N, res;
bool prime[MAX];

bool check_num(int num) {
	string str = to_string(num);
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - 1 - i]) return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(prime, true, sizeof(prime));
	prime[1] = false;

	for (int i = 2; i < MAX; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j < MAX; j += i) {
			prime[j] = false;
		}
	}

	cin >> N;
	for (int i = N; i < MAX; i++) {
		if (prime[i] && check_num(i)) {
			res = i;
			break;
		}
	}

	cout << res;
	return 0;
}
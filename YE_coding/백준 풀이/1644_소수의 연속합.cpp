//백준 https://www.acmicpc.net/problem/1644
//소수의 연속합
#include<iostream>

using namespace std;

int N, res;
bool prime[4000001];

int nextPtr(int p) {
	p += 1;
	while (p <= N && prime[p]) p++;

	return p;
}

int main() {
	int ptr1, ptr2, sum;

	cin >> N;

	for (int i = 2; i <= N; i++) {
		if (prime[i]) continue;
		for (int j = i + i; j <= N; j += i)
			prime[j] = true;
	}

	ptr1 = ptr2 = sum = 2;

	while (ptr2 <= N) {
		if (sum == N) {
			res++;
			sum -= ptr1; ptr1 = nextPtr(ptr1);
			ptr2 = nextPtr(ptr2); sum += ptr2;
		}
		else if (sum < N) {
			ptr2 = nextPtr(ptr2);
			sum += ptr2;
		}
		else {
			sum -= ptr1; ptr1 = nextPtr(ptr1);
		}
	}

	cout << res << '\n';
	return 0;
}
//백준 https://www.acmicpc.net/problem/11003
//최솟값 찾기
#include<iostream>
#include<deque>

using namespace std;

const int MAX = 5000000;

int N, L;
int arr[MAX];
deque<pair<int, int>> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		if (!dq.empty() && dq.front().first <= i - L)
			dq.pop_front();

		while (!dq.empty() && dq.back().second >= arr[i])
			dq.pop_back();

		dq.push_back(make_pair(i, arr[i]));
		cout << dq.front().second << " ";
	}

	cout << "\n";
	return 0;
}
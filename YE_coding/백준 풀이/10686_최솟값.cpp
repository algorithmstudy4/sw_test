//백준 https://www.acmicpc.net/problem/10868
//최솟값
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 2147000000;

int N, M;
int arr[100001], tree[400001];

int init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int minimum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return MAX;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(minimum(node * 2, start, mid, left, right), minimum(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> arr[i];
	init(1, 0, N - 1);

	int a, b;
	while (M--) {
		cin >> a >> b;

		cout << minimum(1, 0, N - 1, a - 1, b - 1) << '\n';
	}

	return 0;
}#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 2147000000;

int N, M;
int arr[100001], tree[400001];

int init(int node, int start, int end) {
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int minimum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return MAX;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(minimum(node * 2, start, mid, left, right), minimum(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> arr[i];
	init(1, 0, N - 1);

	int a, b;
	while (M--) {
		cin >> a >> b;

		cout << minimum(1, 0, N - 1, a - 1, b - 1) << '\n';
	}

	return 0;
}
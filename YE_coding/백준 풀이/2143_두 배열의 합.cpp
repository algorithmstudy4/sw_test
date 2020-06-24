//백준 https://www.acmicpc.net/problem/2143
//두 배열의 합
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T, A[1000], B[1000];
long long res;
vector<long long> vecA, vecB;

int main() {
	int N, M;
	long long sum;

	cin >> T;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	cin >> M;
	for (int i = 0; i < M; i++) cin >> B[i];

	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			vecA.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) {
		sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			vecB.push_back(sum);
		}
	}

	sort(vecB.begin(), vecB.end());
	for (int i = 0; i < vecA.size(); i++) {
		int num = T - vecA[i];
		int low = lower_bound(vecB.begin(), vecB.end(), num) - vecB.begin();
		int high = upper_bound(vecB.begin(), vecB.end(), num) - vecB.begin();

		res += (high - low);
	}

	cout << res;
	return 0;
}
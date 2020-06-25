//백준 https://www.acmicpc.net/problem/1484
//다이어트
#include<iostream>

using namespace std;

int main() {
	int G, lo, hi, weight;
	bool flag = true;

	cin >> G;

	lo = 1; hi = 2;
	while (1) {
		weight = hi * hi - lo * lo;

		if (weight > G) {
			if (hi == lo + 1) break;
			lo++;
		}
		else {
			if (weight == G) {
				flag = false;
				cout << hi << '\n';
			}

			hi++;
		}
	}

	if (flag) cout << "-1\n";
	return 0;
}

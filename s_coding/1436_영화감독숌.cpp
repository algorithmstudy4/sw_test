#if 0
//영화감독숌
//https://www.acmicpc.net/problem/1436
#include <iostream>
using namespace std;
int main() {

  freopen("input.txt", "r", stdin);
	int n,num,remainder=0,six_cnt=0,cnt=0;
	cin >> n;

	for (int i = 666;; i++){
		six_cnt = 0;
		num = i;
		while (num) {
			if (num % 10 == 6)six_cnt++;
			else if(six_cnt<3)six_cnt=0;
			num /= 10;
		}
		if (six_cnt >= 3)cnt++;
		if (n == cnt) { cout << i; return 0; }
	}
	return 0;
}

#endif

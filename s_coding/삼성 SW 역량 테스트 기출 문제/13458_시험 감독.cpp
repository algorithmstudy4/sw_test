#if 0
//시험 감독
//https://www.acmicpc.net/problem/13458
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector <int> v;
int N,B,C;
long long total; 
void Solve() {

	for (int i = 0; i < N; i++) {
		total++; //총감독관
	
		v[i] -= B;
		
		//if(v[i]>=0)total += (ceil((double)v[i] / C));

		if (v[i] > 0) {
			total += (v[i] / C);

			if (v[i] % C != 0) {
				total++;
			}
		}
	}
}
int main() {

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int people;
		scanf("%d", &people);
		v.push_back(people);
	}

	scanf("%d %d", &B, &C);

	Solve();

	printf("%lld", total);

	return 0;
}
#endif

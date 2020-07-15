//백준 https://www.acmicpc.net/problem/10825
//국영수
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct student {
	string name;
	int ko, en, math;

	bool operator<(const student& s)const {
		if (ko == s.ko && en == s.en && math == s.math)
			return name < s.name;
		else if (ko == s.ko && en == s.en)
			return math > s.math;
		else if (ko == s.ko)
			return en < s.en;
		else return ko > s.ko;
	}
};

int main() {
	int N;
	cin >> N;

	vector<student> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec[i].name >> vec[i].ko >> vec[i].en >> vec[i].math;
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++)
		cout << vec[i].name << '\n';

	return 0;
}
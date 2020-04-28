//https://www.acmicpc.net/problem/2309
//일곱난쟁이

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int sum = 0;
	vector<int> tall;

	int temp;
	for (int i = 0;i < 9;i++) {
		cin >> temp;
		tall.push_back(temp);
		sum +=temp;
	}

	int index_1, index_2;

	for (int i = 0;i < 9;i++) {
		for (int j = i + 1;j < 9;j++) {
			if (tall[i] + tall[j] == sum - 100) {
				index_1 = tall[i];
				index_2 = tall[j];
				break;
			}
		}
	}

	sort(tall.begin(),tall.end());

	for (int i = 0;i < 9;i++) {
		if (tall[i] != index_1 && tall[i] != index_2){
			cout << tall[i] << endl; }
	}

}
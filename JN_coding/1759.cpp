//https://www.acmicpc.net/problem/1759
//암호만들기

#include<iostream>
#include<vector>
#include<algorithm>
#define CMAX 16

//모음 con 자음 vow

using namespace std;

string input[CMAX];
int L, C;

bool iscon(int index) {
	if (input[index] == "a" || input[index] == "e" || input[index] == "i" || input[index] == "o" || input[index] == "u") {
		return true;
	}
	else {
		return false;
	}
}

void getCode(int index,int conNum,int vowNum,string picked,int cnt) {
	if(cnt==L){
		if (conNum >= 1 && vowNum >= 2)
			cout << picked << endl;
		return;
	}

	if (index == C)	return;

	if (iscon(index)) {
		getCode(index + 1, conNum + 1, vowNum, picked+input[index],cnt+1);
	}
	else {
		getCode(index + 1, conNum , vowNum+1, picked+input[index],cnt+1);
	}
	getCode(index + 1, conNum, vowNum, picked,cnt);

}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> input[i];
	}

	sort(input, input + C);
	
	getCode(0, 0, 0, "",0);
}
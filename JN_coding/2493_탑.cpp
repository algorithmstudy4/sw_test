//https://www.acmicpc.net/problem/2493
//2593. ž

#include<iostream>
#define MAX 500001
using namespace std;

int N;
int input[MAX];
int result[MAX];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin>>input[i];
	}

	int max =input[0];
	result[0] = 0;
	for (int i = 1; i < N; i++) {
		if (input[i] > max) {
			max = input[i];
			result[i] = 0;
		}
		else{
		if (input[i] >= input[i - 1])	result[i] = result[i - 1];
		else {
			result[i] = i;
		}}
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
}
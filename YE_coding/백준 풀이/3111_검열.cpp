//백준 https://www.acmicpc.net/problem/3111
//검열
#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {
	string str, del;
	cin >> del >> str;

	int f = 0;
	int b = str.length() - 1;
	deque<char> front, back;
	bool reverse = false;

	while (f <= b) {
		bool flag = true;
		if (reverse) {
			back.push_front(str[b--]);

			if (back.front() == del[0] && back.size() >= del.length()) {
				for (int i = 1; i < del.length(); i++) {
					if (back[i] != del[i]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int i = 0; i < del.length(); i++) back.pop_front();
					reverse = !reverse;
				}
			}
		}
		else {
			front.push_back(str[f++]);

			int d = del.length() - 1;
			if (front.back() == del[d] && front.size() >= del.length()) {
				for (int i = 1; i < del.length(); i++) {
					if (front[front.size() - 1 - i] != del[d - i]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int i = 0; i < del.length(); i++) front.pop_back();
					reverse = !reverse;
				}
			}
		}
	}

	string res;
	for (int i = 0; i < front.size(); i++) res += front[i];
	for (int i = 0; i < back.size(); i++) res += back[i];

	while (res.find(del) < res.length()) {
		res.erase(res.find(del), del.length());
	}

	cout << res;
	return 0;
}

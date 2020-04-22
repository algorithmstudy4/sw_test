//https://www.acmicpc.net/problem/9012
//괄호

include<iostream>
#include<stack>

using namespace std;

int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		string input;
		cin >> input;

		stack<int> ps;
		bool is_ps = true;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(')	ps.push(1);
			if (input[i] == ')' && ps.size() == 0) { is_ps = false; }
			if (input[i] == ')' && ps.size() != 0) { ps.pop(); }

			if (is_ps == false)	break;
		}

		if (is_ps == true && ps.size()==0)	cout << "YES" << "\n";
		else	cout << "NO" << "\n";
	}
}
#if 0
//카카오 블라인드 문자열압축
//https://programmers.co.kr/learn/courses/30/lessons/60057

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length(); 

	if (s.length() == 1)return 1; 

	for (int i = 1; i <= s.length() / 2; i++) {
		int cnt = 1;
		string str = s.substr(0, i);
		string cmp;
		string result; 

		for (int j = i; j < s.length(); j += i) {
			cmp = s.substr(j, i);

			if (str.compare(cmp) == 0) {
				cnt++;
			}
			else {
				if (cnt == 1) {
					result += str;
					str = cmp; 
				}
				else {
					result = result + to_string(cnt) + str;
					str = cmp;
					cnt = 1; 
				}
			}
			if (i + j >= s.length()) { 
				if (cnt == 1) {
					result = result + s.substr(j); 
					break;
				}
				else {
					result = result + to_string(cnt) + str;
					break;
				}

			}

		}
	
		answer = (answer > result.length()) ? result.length() : answer;
	}
	return answer;
}
#endif

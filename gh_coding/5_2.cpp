// 프로그래머스
// 2단계 카펫
// https://programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1 ; i <= yellow; i ++) {
        if (yellow%i != 0) continue;
        int line = yellow/i; // 가로 갯수
        if (line < i) continue;
        int total = line * 2 + (i+2) * 2;
        if (brown == total) {
            answer.push_back(line+2);
            answer.push_back(i+2);
        }
        
    }
    return answer;
}
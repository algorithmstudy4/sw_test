#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
// 프로그래머스 문제 '기능개발' 
// 스택/큐 2단계
// https://programmers.co.kr/learn/courses/30/lessons/42586
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> works;
    for (int i = 0 ; i < progresses.size();  i++) {
        
        works.push(ceil((100-progresses[i])/(float)speeds[i]));
    }
    while(!works.empty()) {
        int t = works.front();
        int n = 1;
        works.pop();
        cout << t << "\n";
        
        while(t > works.front() && works.size() > 0) {
            n++;
            works.pop();
        }
        answer.push_back(n);
    }
    
    return answer;
}

int main(void) {
    vector<int> p = {93,30,55};
    vector<int> s = {1,30,5};
    vector<int> ans = solution(p, s);
    cout << "\n\n";
    for (int i : ans)
        cout << i << " ";
    return 0;
}

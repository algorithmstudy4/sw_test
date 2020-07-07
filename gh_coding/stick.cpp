// 프로그래머스'쇠막대기'
// 스택/큐 
// https://programmers.co.kr/learn/courses/30/lessons/42585

#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
//
//int solution(string arrangement) {
//    stack<int> stk2;
//    vector<pair<int,int>> sticks;
//    vector<int> cuts;
//    for (int i=0; i<arrangement.size(); i++) {
//        if (arrangement[i] == '(') {
//            stk2.push(i);
//        } else {
//            int top = stk2.top();
//            stk2.pop();
//            if (i - top == 1) {
//                cuts.push_back(top);
//            } else {
//                sticks.push_back(make_pair(top, i));
//            }
//        }
//    }ㅁ
//    map<int,int> checks;
//    int total = 0;
//    for (int c : cuts) {
//        for (pair<int,int> s: sticks) {
//            if (s.first < c && s.second > c) {
//                if (checks[s.first] == 1) {
//                    total += 1;
//                } else {
//                    total += 2;
//                    checks[s.first] = 1;
//                }
//            } else {
//            }
//        }
//    }
//    return total;
//}
int solution(string arrangement) {
    stack<int> stk2;
    int total = 0;
    int first = false;
    for (int i=0; i<arrangement.size(); i++) {
        if (arrangement[i] == '(') {
            stk2.push(i);
        } else {
            int top = stk2.top();
            stk2.pop();
            if (i - top != 1) total += 1;
            else total += stk2.size();
            
        }
    }

    return total;
}
int main(void) {
    
    cout << solution("()(((()())(())()))(())");
    
    
}

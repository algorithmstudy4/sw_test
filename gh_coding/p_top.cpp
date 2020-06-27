#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
// 프로그래머스 문제 '탑'
// 스택/큐 2단계
// https://programmers.co.kr/learn/courses/30/lessons/42588
vector<int> solution(vector<int> heights) {
   vector<int> answer;
   for (int i = (int)heights.size() -1 ; i >= 0; i --) {
       if (i == 0) answer.push_back(0);
       else {
           int in = false;
           for (int j = i-1; j >= 0 ; j--) {
               if (heights[i] < heights[j]) {
                   answer.push_back(j+1);
                   in = true;
                   break;
               }
           }
           if (!in) { answer.push_back(0); }
       }
   }
   reverse(answer.begin(), answer.end());
   return answer;
}
int main(void) {
   vector<int> an = {3,9,9,3,5,7,2};
   vector<int>result = solution(an);
   for (int i : result)
       cout << i << " ";
}

// 리트코드 Generate parentheses
// 미듐 문제
// https://leetcode.com/problems/generate-parentheses/


#include <string>
#include <vector>
#include<stack>
#include<map>
#include<iostream>
#include<stdio.h>
using namespace std;
//
class Solution {
public:
    vector<string> answer;
    vector<string> generateParenthesis(int n) {

        greedy(n, 0, 0, 0, "");
        return answer;
    }
    void greedy(int n , int cur, int open, int close, string s) {
        if (cur == 2 * n && open == n && close == n) {
            answer.push_back(s);
            return;
        } else if (cur == n * 2) {
            return;
        }
        if (open < close) {
            return;
        }
        greedy(n, cur+1, open+1, close, s+"(");
        greedy(n, cur+1, open, close+1, s+")");
    }
}
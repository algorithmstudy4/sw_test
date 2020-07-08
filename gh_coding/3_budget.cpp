#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
// 프로그래머스 3단계
// 예산 (이분탐색)
// https://programmers.co.kr/learn/courses/30/lessons/43237
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    sort(budgets.begin(), budgets.end());
    int n = (int)budgets.size();
    int right = budgets[n-1];
    int left = budgets[0];
    while(left<=right) {
        int mid = (left+right)/2;
        int t_sum =  0;
        for (int bud : budgets) {
            t_sum += bud > mid ? mid : bud;
        }
        if (t_sum <= M) {
            answer = answer > mid ? answer : mid;
            left = mid +1;
        } else {
            right = mid -1;
        }
        
    }
    return answer;
}
int main(void) {
    vector<int> bud = {120, 110,140,150};
    cout << solution(bud, 485);
    return 0;
}

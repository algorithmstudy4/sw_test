// 프로그래머스
// 라면공장
// https://programmers.co.kr/learn/courses/30/lessons/42629
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int solution(int stock, vector<int> dates, vector<int> supplies, int k){
    int answer = 0;
    priority_queue<int> pq;
    for (int day = 0, j = 0; day < k; day++){
        if (dates.size() > j && dates.at(j) <= day){
            pq.push(supplies.at(j));
            j++;
        }
        if (!stock){
            stock += pq.top();
            pq.pop();
            answer++;
        }
        //밀가루 사용
        stock--;
    }
    return answer;
}
#include <string>
#include <vector>
#include<iostream>
#include<climits>
#include<algorithm>
// 프로그래머스 3단계 
// 이분탐색 3단계
// https://programmers.co.kr/learn/courses/30/lessons/43238
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long end = (long long)times[times.size()-1] * n;
    long long min_answer = end;
    long long start = 1;
    while(start <= end) {
        long long cnt = 0;
        long long mid = (end + start) /2;
        
        for (int j = 0 ; j < times.size(); j ++) {
            cnt += mid / times[j];
        }
        if (n > cnt) {
            start = mid +1;
        } else {
            
            if (mid <= min_answer)
                min_answer = mid;
            end = mid - 1;
        }
        
    }
    return min_answer;
}
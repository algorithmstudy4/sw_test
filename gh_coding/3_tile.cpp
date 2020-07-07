#include <string>
#include <vector>
#include<iostream>
using namespace std;
// 프로그래머스 DP 3단계
// 타일장식물
// https://programmers.co.kr/learn/courses/30/lessons/43104
long long solution(int N) {
    long long answer = 0;
    vector<int> ary;
    ary.assign(N, 0);
    ary[0] = 1; ary[1] = 1;
    for (int i = 2 ; i < N; i ++) {
        ary[i] = ary[i-1] + ary[i-2];
    }
    answer += ary[N-1] * 2 + (ary[N-2]+ary[N-1]) * 2;
    return answer;
}

int main(void) {
    
    cout << solution(2);
    
    return 0;
}

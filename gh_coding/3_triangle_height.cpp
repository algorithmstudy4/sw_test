#include <string>
#include <vector>
#include<iostream>
using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/43105
// 프로그래머스 3단계 DP
// 정수 삼각형
int solution(vector<vector<int>> triangle) {
    int answer = 0;
//    return answer;
    for (int i = 1 ; i < (int)triangle.size();  i++){
        for (int j = 0 ; j < triangle[i].size() ; j ++) {
            if (j==triangle[i].size()-1) {
                triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
            } else if (j == 0 ) {
                triangle[i][j] = triangle[i][j] + triangle[i-1][j];
            }else {
                triangle[i][j] = triangle[i-1][j-1] > triangle[i-1][j] ? triangle[i-1][j-1] + triangle[i][j] : triangle[i-1][j] + triangle[i][j];
            }
        }
    }
    int N = (int)triangle.size()-1;
    for (int i = 0 ; i < triangle[N].size() ; i ++){
        answer = triangle[N][i] >  answer ? triangle[N][i] : answer;
    }
    return answer;
}

int main(void) {
    vector<vector<int>> input = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    cout << solution(input);
}

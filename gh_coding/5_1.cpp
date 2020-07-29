#include <iostream>
#include <string>
// 가장 긴 팰린드롬 
// 프로그래머스 3단계
// https://programmers.co.kr/learn/courses/30/lessons/12904
using namespace std;
int solution(string s)
{   
    int len = s.size();
    
    while(len >= 2){ 
        for(int i=0;i<=s.size() - len;i++){  
                 int left = i;
                 int right = len+i-1;
                 bool flag = true;
            while(left < right){  // 실제로 펠린드롬인지 확인
                if(s[left] != s[right]){
                    flag = false;
                    break;
                }
                left++;
                right--;
            }
            if(flag){
                return len;
            }
        }
        len--;
    }
    return 1;
}
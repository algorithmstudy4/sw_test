//https://programmers.co.kr/learn/courses/30/lessons/12925
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
   
     int answer =0;
     bool flag = false;
    
    for(int i=0;i<s.size();i++){
        if(s[i] == '-'){
            flag =true;
        }
        else if (s[i] == '+'){
            flag = false;
        }
        else {
            int str  = s[i] - '0';
            answer = answer*10 + (int)str;
            
        }
        
    }
    if(flag){
        answer = -answer;
    }
    return answer;
}

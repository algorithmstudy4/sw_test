#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    for(int i = 0; i < s.size(); i++) {
      
        if(s[i] == ' ') {
          answer += " ";
          flag = true;
      }
      else {
          if(flag) {
              flag = false;
              if(s[i] >= 'A' && s[i] <= 'Z') answer += s[i];
              else {
                  answer += s[i] - 32;
              }
              
          }
          else {
              flag = true;
              if(s[i] >= 'a' && s[i] <= 'z') answer += s[i];
              else {
                   answer += s[i] + 32;
              }
             

          }
      }
    }
    return answer;
}

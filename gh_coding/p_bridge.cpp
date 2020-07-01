#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;
// 프로그래머스 '다리를 지나는 트럭'
// 스택/큐 2단계
// https://programmers.co.kr/learn/courses/30/lessons/42583
int solution(int bridge_length, int weight, vector<int> truck_weights) {
   int answer = 0;
   queue<int> que;
   int total_size = 0;
   for (int i = 0 ; i < truck_weights.size(); i ++) {
       int size = truck_weights[i];
       while(1) {
        
           if (que.empty()) {
               que.push(size);
               total_size += size; answer++;
               break;
           } else if (que.size() == bridge_length){
               total_size -= que.front();
               que.pop();
           } else {
               if (total_size + size > weight) {
                   que.push(0); answer ++;
               } else {
                   que.push(size);
                   total_size += size; answer++;
                   break;
               }
           }
       }
   }
   return answer + bridge_length;
}
int main(void){
   vector<int> weights = {7,4,5,6};
   cout << solution(2, 10, weights);
}

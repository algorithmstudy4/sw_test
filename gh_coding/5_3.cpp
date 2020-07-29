// 프로그래머스
// 이중 우선순위큐 
// https://programmers.co.kr/learn/courses/30/lessons/42628#

#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <set>
 
using namespace std;
 
vector<int> solution(vector<string> operations) {
    multiset<int> mset;
    for (auto o : operations) {
        string a = o.substr(0, 1);
        int num = atoi(o.substr(2).c_str());
        if (a == "I")     mset.insert(num);
        else if (!mset.empty()) {
            if (num == 1)    mset.erase(--mset.end());
            else    mset.erase(mset.begin());
        }
    }
    if (mset.empty())    return { 0 , 0 };
    else    return { *--mset.end() , *mset.begin() };
}
 
vector<int> solution2(vector<string> operations) {
    deque<int> deq;
    for (auto o : operations) {
        string a = o.substr(0, 1);
        int num = atoi(o.substr(2).c_str());
        if (a == "I")     deq.push_back(num);
        else if (!deq.empty()) {
            sort(deq.begin(), deq.end());
            if (num == 1)    deq.pop_back();
            else    deq.pop_front();
        }
    }
    if (deq.empty())    return { 0,0 };
    sort(deq.begin(), deq.end());
    return { deq.back(), deq.front() };
}
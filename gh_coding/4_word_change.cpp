#include <stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int min_n = 100;
// 프로그래머스 단어 변환 
// DFS/BFS 3단계
// https://programmers.co.kr/learn/courses/30/lessons/43163
bool checks[50] = { 0};
bool diffOneChar(string a, string b) {
    int cnt = 0;
    for (int i = 0 ; i <a.size() ; i ++) {
        if (a[i] != b[i]) {
            cnt ++;
        }
    }
    if (cnt == 1) {
        return true;
    } else return false;
}
void dfs(int n, string begin, string target , vector<string>words) {
    for (int i = 0 ; i < words.size() ; i++) {
        // if(checks[i]) continue;
        if (diffOneChar(words[i], begin)) {
            if (!words[i].compare(target)) {
                min_n = min_n > n+1 ? n+1 : min_n;
            }
            if (!checks[i]) {
                checks[i] = true;
                dfs(n+1, words[i], target,words);
                checks[i] = false;

            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(0, begin, target, words);
    if (min_n == 100) {
        return 0;
    } else {
        return min_n;
    }
}
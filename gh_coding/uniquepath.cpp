#include<iostream>
using namespace std;
// 리트코드 문제 'unique path' 
// dp medium
// https://leetcode.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m== 1 && n == 1) {
            return 1;
        }
        int * arr = new int[n]();
        for (int i = 1; i<n; i++)
            arr[i] = 1;
        
        for (int i = 1; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if ( j== 0){
                    arr[j] = 1;
                } else {
                    arr[j] = arr[j-1] + arr[j];
                }
            }
        }
        return arr[n-1];
        
    }
};
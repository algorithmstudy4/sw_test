// 리트코드 문제 'unique path ii' 
// dp medium
// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = (int) obstacleGrid[0].size();
        if (n== 1) {
            for (int i = 0; i < obstacleGrid.size(); i ++) {
                if (obstacleGrid[i][0]) return 0;
            }
            return 1;
        } else if (obstacleGrid.size() == 1) {
            for (int i = 0 ; i < obstacleGrid[0].size(); i ++) {
                if (obstacleGrid[0][i]) return 0;
            }
            return 1;
            
        }
        int value = 1;
        int * arr = new int[n]();
        for (int i = 0; i < n;i++) {
            if (obstacleGrid[0][i] == 1) value = 0;
            arr[i] = value;
        }
        for (int i = 1 ; i < obstacleGrid.size(); i ++) {
            for (int j = 0; j < n ; j ++) {
                if (j==0) {
                    if (obstacleGrid[i][j]) {
                        arr[j] = 0;
                    } else {
                        arr[j] = arr[j];
                    }
                } else {
                    if (obstacleGrid[i][j]) {
                        arr[j] = 0;
                    } else {
                        arr[j] = arr[j-1] + arr[j];
                    }

                }
            }
        }
        
        return arr[n-1];
    }
};
class Solution {
public:

   
    int threeSumClosest(vector<int>& nums, int target) {
        int min = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() -1; i ++) {
            int s = i, e = i+1;
            int n = (int)nums.size() - 1;
            while(e < n) {

                int sum = nums[s] + nums[e] + nums[n];
                printf("%d %d %d %d\n",s,e,n, sum);

                if (sum < target) {
                    e++;
                } else if (sum > target) {
                    n --;
                } else {
                    return sum;
                }
                min = abs(target-sum) < min ? sum : min;
            }

        }
        
        return min;
    }
    

};
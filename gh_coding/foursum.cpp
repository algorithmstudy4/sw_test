class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        else if (nums.size() == 4) {
            int sum = 0;
            for (int c : nums) sum += c;
            if (sum == target) {
                ans.push_back(nums);
            }
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int n : nums)
            cout << n << " ";
        cout << "\n\n";
        for (int i = 0 ; i < (int)nums.size()-1; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int s1 = i;
            int s2 = i+1;
            int e1 = (int)nums.size()-1;
            int e2 = e1-1;
            if (i > 0 && nums[e1] == nums[e2]) continue;
            while(s2 < e2) {
                int sum = nums[s1] + nums[s2] + nums[e1] + nums[e2];
                if (sum < target) {
                    printf("up : %d %d %d %d\n", s1,s2,e2,e1);
                    s2 ++;
                } else if (sum > target) {
                    printf("down : %d %d %d %d\n", s1,s2,e2,e1);
                    if (e1-e2 == 1) e2 --;
                    else e1 --;
                } else {
                    printf("correct : %d %d %d %d\n", s1,s2,e2,e1);

                    vector<int> t;
                    t.push_back(nums[s1]);t.push_back(nums[s2]);t.push_back(nums[e2]);t.push_back(nums[e1]);
                    ans.push_back(t);
                    s2 ++; e2 --;
                    while(nums[s2] == nums[s2-1]) s2++;
                    while(nums[e2] == nums[e2+1]) e2 --;
//                    e1 = e2 + 1;
                }
            }
        }
        // 0 1 2 4

        cout << ans.size();
        
        return ans;
        
    }
   

};
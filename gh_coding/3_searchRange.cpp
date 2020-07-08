#include<iostream>
#include<vector>
using namespace std;
// 리트코드
// 미듐 'Find First and Last Position of Element in Sorted Array'
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start = 0;
        int end = (int)nums.size();
        if (end == 0) {
            ans.push_back(-1); ans.push_back(-1);
            return ans;
        }
//        else if (end == 1) {
//            if (nums[0] == target) {
//                ans.push_back(0); ans.push_back(0);
//            } else {
//                ans.push_back(-1); ans.push_back(-1);
//
//            }
//            return ans;
//        }
        while(start<=end) {
//            cout << "s :" << start << ", e :" << end << "\n";
            int mid = (start+end)/2;
            if (nums[mid] > target) {
                start = mid +1;
            } else {
                end = mid -1;
                if (target == nums[mid]) {
                    int s = mid;
                    while(s >= 0  && nums[s] == target) s --;
                    ans.push_back(s+1);
                    int e = mid;
                    while (e < (int)nums.size() && nums[e] == target) e++;
                    ans.push_back(e-1);
                    break;
                }
            }
        }
        if ((int)ans.size() == 0)
        {
            ans.push_back(-1); ans.push_back(-1);
        }
        return ans;
    }
};
int main(void) {
    Solution s;
    vector<int>input = {2,2};
    vector<int> ans = s.searchRange(input, 2);
    for (int a : ans)
        cout << a <<" ";
}

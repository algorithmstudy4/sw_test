
// 프로그래머스 '타겟넘버'
// dfs/bfs 2단계
// https://programmers.co.kr/learn/courses/30/lessons/43165
#include<iostream>
#include <vector>
using namespace std;
int final = 0;
void sol1(vector<int> nums, int n, int sum, int target) {
	if (n == nums.size()-1) {


		if (sum + nums[n] == target) {
			final += 1;
			return;
		}
		if (sum - nums[n] == target) {
			final += 1;
			return;
		}
		else {
			return;
		}
	} 
	sol1(nums, n+1, sum + nums[n], target);
	sol1(nums, n+1, sum - nums[n], target);
	
}
int solution(vector<int> numbers, int target) {
	int answer = 0;
	sol1(numbers, 0, 0, target);
	return final;
}
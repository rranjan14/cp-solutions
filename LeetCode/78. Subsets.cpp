/*
78. Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        int total = pow(2,len);
        for(int i=0;i<total;i++){
            vector<int> set;
            for(int j=0;j<len;j++){
                if((i & (1 << j)) != 0){
                    set.push_back(nums[j]);
                }
            }
            result.push_back(set);
        }
        return result;
    }
};
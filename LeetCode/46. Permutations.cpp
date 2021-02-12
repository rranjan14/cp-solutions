/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/

class Solution {
public:
    vector<vector<int>> result;

    void swap(int &a, int &b){
        int temp = b;
        b = a;
        a = temp;
        
    }
        
    void permutation(vector<int> &nums, int l, int r){
        if(l == r)
            result.push_back(nums);
        else
            for(int i=l; i<=r; i++){
                swap(nums[i], nums[l]);
                permutation(nums, l+1, r);
                swap(nums[i], nums[l]);
            }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int last = nums.size()-1;
        permutation(nums,0,last);
        return result;
    }
};
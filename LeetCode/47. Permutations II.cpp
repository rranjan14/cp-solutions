/*
47. Permutations II

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
public:
    set<vector<int>> unique;
    void swap(int& num1,int& num2){
        int temp = num1;
        num1=num2;
        num2=temp;
    }
    void permute(vector<int>& num,int l,int r){
        if(l==r){
            unique.insert(num);
        }else{
            for(int i=l;i<=r;i++){
                swap(num[i],num[l]);
                permute(num,l+1,r);
                swap(num[i],num[l]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int last = nums.size()-1;
        permute(nums,0,last);
        vector<vector<int>> result(unique.begin(),unique.end());
        return result;
    }
};
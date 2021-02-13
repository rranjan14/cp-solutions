/*
77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Example 2:
Input: n = 1, k = 1
Output: [[1]]
*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    void solve(int digit,int n,int k){
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        for(int i=digit;i<=n;i++){
            temp.push_back(i);
            solve(i+1,n,k);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        solve(1,n,k);
        return result;
    }
};
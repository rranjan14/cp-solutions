/*


784. Letter Case Permutation

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.
Return a list of all possible strings we could create. You can return the output in any order.

Example 1:
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: S = "3z4"
Output: ["3z4","3Z4"]

Example 3:
Input: S = "12345"
Output: ["12345"]

Example 4:
Input: S = "0"
Output: ["0"]

*/

class Solution {
public:
    vector<string> result;
    void solve(int pos,string s){
        result.push_back(s);
        for(int i=pos;i<s.size();i++){
            if(!isalpha(s[i]))
                continue;
            if(s[i]>='a' && s[i]<='z'){
                s[i]-=32;
                solve(i+1,s);
                s[i]+=32;
            }
            if(s[i]>='A' && s[i]<='Z'){
                s[i]+=32;
                solve(i+1,s);
                s[i]-=32; 
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        solve(0,S);
        return result;
    }
};
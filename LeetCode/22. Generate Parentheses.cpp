/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
*/

class Solution {
public:
    vector<string> result;
    char s[200];
    void generateParenthesis(int n,int pos,int o,int c){
        if(c==n)
            result.push_back(s);
        else{
            if(o>c){
                s[pos]=')';
                generateParenthesis(n,pos+1,o,c+1);
            }
            if(o<n){
                s[pos]='(';
                generateParenthesis(n,pos+1,o+1,c);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        generateParenthesis(n,0,0,0);
        return result;
    }
};
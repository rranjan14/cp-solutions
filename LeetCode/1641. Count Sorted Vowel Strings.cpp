/*

Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].

Example 2:
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

Example 3:
Input: n = 33
Output: 66045
*/


class Solution {
public:
    int cnt=0;
    string s="aeiou";
    string temp="";
    void solve(int n,int src){
        if(temp.size()==n){
            cnt++;
            return;
        }
        for(int i=src;i<s.size();i++){
            temp.push_back(s[i]);
            solve(n,i);
            temp.pop_back();
        }
    }
    int countVowelStrings(int n) {
        solve(n,0);
        return cnt;
    }
};
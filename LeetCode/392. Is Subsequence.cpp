/*

Given two strings s and t, check if s is a subsequence of t.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false

Constraints:
    1. 0 <= s.length <= 100
    2. 0 <= t.length <= 104
    3. s and t consist only of lowercase English letters.

*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int substringIndex = 0;
        for(auto x:t){
            if(x==s[substringIndex])
                substringIndex++;
        }
        return substringIndex == s.size() ? true:false;
    }
};
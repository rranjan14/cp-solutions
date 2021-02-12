/*

1415. The k-th Lexicographical String of All Happy Strings of Length n

A happy string is a string that:
    1.consists only of letters of the set ['a', 'b', 'c'].
    2.s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).

For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

Example 1:
Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

Example 2:
Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.

Example 3:
Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"

Example 4:
Input: n = 2, k = 7
Output: ""

Example 5:
Input: n = 10, k = 100
Output: "abacbabacb"

*/

class Solution {
public:
    vector<string> result;
    string letters="abc";
    string temp="";
    void solve(int n,char last){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<3;i++){
            if(last !=letters[i]){
                temp.push_back(letters[i]);
                solve(n,letters[i]);
                temp.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        char c='.';
        solve(n,c);
        if(k>result.size())
            return "";
        return result[k-1];
    }
};
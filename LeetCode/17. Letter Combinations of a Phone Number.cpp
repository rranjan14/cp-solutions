/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/

class Solution {
public:
    map<char,string> m={
    {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
    };
    
    vector<string> result;
    
    void combination(string d,int p,string str){
        if(p==d.size()) result.push_back(str);
        for(int i=0;i<m[d[p]].size();i++){
            str.push_back(m[d[p]][i]);
            combination(d,p+1,str);
            str.pop_back();
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string str = "";
        combination(digits,0,str);
        return result;
    }
};
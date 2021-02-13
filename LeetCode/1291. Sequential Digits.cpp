/*

1291. Sequential Digits

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

*/

class Solution {
public:
    vector<int> result;
    void solve(char i,int low,int high,string s){
        s=s+i;
        int t=stoi(s);
        if(t>=low&&t<=high)
            result.push_back(t);
        if(i=='9')
            return;
        solve(i+1,low,high,s); 
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i='1';i<='9';i++){
            solve(i,low,high,"");
        }
        sort(result.begin(),result.end());
        return result;
    }
};
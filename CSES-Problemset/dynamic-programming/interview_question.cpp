/*

Coding interview problem

Find the number of lists that exist and satisfy the following:
    1.  list contains exactly 'N' elements
    2.  all elements of the list are between 'low' and 'high'
    3.  sum of all elements is even

Return answer modulo 10^9+7

Constraints
1 <= n <= 10^6
1 <= low <= high <= 10^6

Sample
(n=3,low=1,high=2) -> 4
(n=2,low=1,high=10) -> 50


*/

#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007;
using namespace std;

void solve()
{
    int n, l, h;
    cin >> n >> l >> h;
    int max_sum = (n * h) % MOD;
    int dp[max_sum + 1][h - l + 1];
    vector<int> nums(h - l + 1);
    for (int i = 0; i <= h - l; i++)
    {
        nums[i] = l;
        l++;
    }

    for (int i = 0; i < nums.size(); i++)
    {
    }
}

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
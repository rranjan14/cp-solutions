#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    int target = n * (n + 1) / 2;
    if (target % 2)
    {
        cout << 0 << endl;
        return;
    }
    target /= 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if (left >= 0)
            {
                (dp[i][j] += dp[i - 1][left]) %= mod;
            }
        }
    }
    cout << dp[n - 1][target] << endl;
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
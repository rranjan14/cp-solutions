#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MOD 1000000007

using namespace std;

void solve()
{

    int n;
    cin >> n;

    vector<string> grid(n);
    int dp[n][n];

    dp[n - 1][n - 1] = 1;

    for (auto &x : grid)
        cin >> x;

    dp[0][0] = grid[0][0] == '.' ? 1 : 0;
    for (int i = 1; i < n; i++)
    {
        if (grid[0][i] == '.')
        {
            dp[0][i] = dp[0][i - 1];
        }
        else
        {
            dp[0][i] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] == '.')
        {
            dp[i][0] = dp[i-1][0];
        }
        else
        {
            dp[i][0] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '*')
                dp[i][j] = 0;
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
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
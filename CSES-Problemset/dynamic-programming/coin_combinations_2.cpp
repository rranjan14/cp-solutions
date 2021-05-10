#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MOD 1000000007

using namespace std;

void solve()
{

    int n, x;
    cin >> n >> x;
    vector<int> coins(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        coins[i] = a;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
            {
                int opt1 = (coins[i] > j) ? 0 : dp[i][j - coins[i]];
                int opt2 = (i == 1) ? 0 : dp[i - 1][j];
                dp[i][j] += (opt1 + opt2) % MOD;
            }
        }
    }

    cout << dp[n][x];
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
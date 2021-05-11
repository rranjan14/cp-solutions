#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> cost(n + 1);
    vector<int> pages(n + 1);

    vector<vector<int>> dp(n + 1, vector<int>(x + 1));

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    for (int i = 1; i <= n; i++)
        cin >> pages[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j == 0 || i == 0)
                dp[i][j] = 0;
            else
            {
                int opt1 = (i == 1) ? 0 : dp[i - 1][j];
                int opt2 = (j < cost[i]) ? 0 : pages[i] + dp[i - 1][j - cost[i]];
                dp[i][j] = max(opt1, opt2);
            }
        }
    }

    cout << dp[n][x] << "\n";
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
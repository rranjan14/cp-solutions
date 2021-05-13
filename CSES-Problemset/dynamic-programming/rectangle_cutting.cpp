#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    for (int height = 1; height <= a; height++)
    {
        for (int width = 1; width <= b; width++)
        {
            if (height == width)
                dp[height][width] = 0;
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i <= width/2; i++)
                    ans = min(ans, 1 + dp[height][width - i] + dp[height][i]);
                for (int i = 1; i <= height/2; i++)
                    ans = min(ans, 1 + dp[height - i][width] + dp[i][width]);
                dp[height][width] = ans;
            }
        }
    }
    cout << dp[a][b] << "\n";
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
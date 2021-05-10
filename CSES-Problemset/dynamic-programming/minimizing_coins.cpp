#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MOD 1000000007

using namespace std;

void solve()
{

    int n, k;
    cin >> k >> n;
    vector<int> coins(k);

    for (auto &x : coins)
        cin >> x;

    vector<int> dp(n + 1, 1e9);

    dp[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (auto x : coins)
        {
            if (x <= i)
                dp[i] = min(dp[i], 1 + dp[i - x]);
        }
    }
    if (dp[n] == 1e9)
        cout << -1 << "\n";
    else
        cout << dp[n] << "\n";
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
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

    vector<int> dp(n);

    dp[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (auto x : coins)
        {
            if (x <= i)
                (dp[i] += dp[i - x]) %= MOD;
        }
    }
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
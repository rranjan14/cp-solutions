#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
void solve()
{
    int n, d, i = 0, cnt = 0;
    bool flag = true;
    string s;
    cin >> n >> d;
    cin >> s;
    vector<int> dp(n,10000);
    dp[0]=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            for (int j = 0; j <= d; j++)
            {
                if (i + j < n && s[i + j] == '1')
                    dp[i+j] = min(dp[i + j], 1 + dp[i]);
            }
        }
    }
    if (dp[n-1] == 10000)
        cout << -1 << "\n";
    else
        cout << dp[n-1] << "\n";
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
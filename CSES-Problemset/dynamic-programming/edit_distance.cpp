#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int l1 = s1.size();
    int l2 = s2.size();
    int dp[l1 + 1][l2 + 1];

    for (int i = 0; i <= l1; i++)
        dp[i][0] = i;
    for (int i = 0; i <= l2; i++)
        dp[0][i] = i;

    for (int i = 1; i <= l1; i++)
        for (int j = 1; j <= l2; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]})+1;

    cout << dp[l1][l2] << "\n";
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
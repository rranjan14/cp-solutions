#include <iostream>

using namespace std;

int main()
{
    string s1 = "QAQ";
    string s2;
    cin >> s2;
    int m = s2.length();
    int n = s1.length();
    int dp[m + 1][n + 1] = {{0}};
    for (int i = 0; i <= n; ++i)
        dp[0][i] = 0;
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s2[i - 1] == s1[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[m][n] << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string X, Y;
    cin >> X;
    cin >> Y;
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (X[i] == t[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = m, j = n;
    string st = "";
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == t[j - 1])
        {
            st.push_back(X[i-1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
                j--;
            else
                i--;
        }
    }
    reverse(st.begin(), st.end());
    cout << st << "\n";
    return 0;
}
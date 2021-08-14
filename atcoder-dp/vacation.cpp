#include <bits/stdc++.h>
using namespace std;
// 2 state DP
int main()
{
    int N, x;
    cin >> N;
    vector<vector<int>> activityPoints(N, vector<int>(3));
    vector<vector<int>> dp(N, vector<int>(3));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> x;
            activityPoints[i][j] = x;
        }
    }

    dp[0][0] = activityPoints[0][0];
    dp[0][1] = activityPoints[0][1];
    dp[0][2] = activityPoints[0][2];

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + activityPoints[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + activityPoints[i][1];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + activityPoints[i][2];
    }

    cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << "\n";
    return 0;
}
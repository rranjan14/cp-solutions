//not accepted

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, W, x, y;
    cin >> N >> W;
    vector<long> weights(N);
    vector<long> values(N);
    vector<vector<long>> dp(N + 1, vector<long>(W + 1, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        weights[i] = x;
        values[i] = y;
    }

    for (int i = 0; i <= N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << dp[N][W] << "\n";
    return 0;
}
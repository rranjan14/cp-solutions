#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> heights(N);
    vector<int> dp(N, INT_MAX);
    for (int &height : heights)
    {
        cin >> height;
    }
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j <= i + K; j++)
        {
            if (j < N)
                dp[j] = min(dp[j], dp[i] + abs(heights[j] - heights[i]));
        }
    }
    cout << dp[N - 1] << "\n";
    return 0;
}
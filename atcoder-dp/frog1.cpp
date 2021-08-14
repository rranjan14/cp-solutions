#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> heights(N);
    for (int &height : heights)
        cin >> height;
    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = abs(heights[1]-heights[0]);
    for (int i = 2; i < N; i++)
    {
        dp[i] = min({dp[i-1]+abs(heights[i]-heights[i-1]),dp[i-2]+abs(heights[i]-heights[i-2])});
    }
    cout << dp[N-1] << "\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve()
{

    int n, cnt = 1, ans = INT_MIN;
    cin >> n;
    vector<int> nums(n);
    for (int &v : nums)
        cin >> v;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] >= nums[i - 1])
            cnt++;
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << ans << "\n";
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
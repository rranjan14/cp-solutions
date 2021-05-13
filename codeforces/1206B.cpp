#include <iostream>
#include <vector>
using namespace std;
void solve()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> nums(n);
    for (int &v : nums)
    {
        cin >> v;
    }
    for (int v : nums)
    {
        if (v < 0)
        {
            cnt += (-1 - v);
        }
        else if (v == 0)
            cnt++;
        else
        {
            cnt += (v - 1);
        }
    }
    cout << cnt << "\n";
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MOD 1000000007

using namespace std;

void solve()
{

    int n, cnt = 0;
    cin >> n;
    while (n)
    {
        int temp = n, max_digit = INT_MIN;
        while (temp)
        {
            max_digit = max(max_digit, temp % 10);
            temp /= 10;
        }
        n -= max_digit;
        cnt++;
    }
    cout << cnt << "\n";
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
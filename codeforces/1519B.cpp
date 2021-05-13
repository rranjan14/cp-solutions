#include <iostream>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (n * m - 1 == k)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
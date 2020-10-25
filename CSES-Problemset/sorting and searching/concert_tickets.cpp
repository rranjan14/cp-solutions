#include <iostream>
#include <set>
using namespace std;
int main()
{
    multiset<int, greater<int>> actual_price;
    int n, m, a;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        actual_price.insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        auto it = actual_price.lower_bound(a);
        if (it == actual_price.end())
            cout << "-1\n";
        else
        {
            cout << *it << "\n";
            actual_price.erase(it);
        }
    }

    return 0;
}
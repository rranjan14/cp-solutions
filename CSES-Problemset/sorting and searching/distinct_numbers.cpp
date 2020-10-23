#include <iostream>
#include <set>
#define lli long long int
using namespace std;
int main()
{
    lli n, x;
    cin >> n;
    set<int, greater<int>> s;
    for (lli i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
    return 0;
}
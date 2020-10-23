#include <iostream>
using namespace std;
#define li long int
#define lli long long int
int main()
{
    li t;
    cin >> t;
    while (t--)
    {
        lli n, m;
        cin >> n >> m;
        cout << ((n + m) % 3 == 0 && (min(n, m) * 2 >= max(n, m)) ? "YES" : "NO") << "\n";
    }
    return 0;
}
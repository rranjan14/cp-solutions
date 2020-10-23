#include <iostream>
#include <vector>
#include <algorithm>
#define vlli vector<long long int>
typedef long long int lli;
using namespace std;
int main()
{
    lli n, x, count = 0;
    cin >> n >> x;
    vlli p(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    lli i = 0, j = n - 1;
    while (i <= j)
    {
        if (p[i] + p[j] <= x)
        {
            count++;
            i++;
            j--;
        }
        else
        {
            j--;
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
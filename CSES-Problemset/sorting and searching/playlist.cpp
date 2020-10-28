#include <iostream>
#include <vector>
#include <map>
#define lli long long int
using namespace std;
int main()
{
    lli n, len = 0, j = 0;
    cin >> n;
    vector<lli> ids(n);
    map<lli, lli> indexes;
    for (lli i = 0; i < n; i++)
    {
        cin >> ids[i];
        indexes[ids[i]] = -1;
    }
    for (lli i = 0; i < n; i++)
    {
        j = max(j, indexes[ids[i]] + 1);
        len = max(len, i - j + 1);
        indexes[ids[i]] = i;
    }
    cout << len;
    return 0;
}
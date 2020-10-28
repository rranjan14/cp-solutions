#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    lli n, x = 0, avg = 0, mid;
    cin >> n;
    vector<lli> lengths(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lengths[i];
    }
    sort(lengths.begin(), lengths.end());
    mid = ceil(n / 2);
    avg = lengths[mid];
    for (int i = 0; i < n; i++)
    {
        x += abs(lengths[i] - avg);
    }
    cout << x;
    return 0;
}
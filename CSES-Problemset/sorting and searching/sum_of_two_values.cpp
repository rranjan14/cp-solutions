#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define lli long long int
using namespace std;
int main()
{
    lli n, x, a;
    cin >> n >> x;
    vector<pair<lli, lli>> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first;
        vec[i].second = i + 1;
    }
    sort(vec.begin(), vec.end());
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (vec[i].first + vec[j].first == x)
        {
            cout << vec[i].second << " " << vec[j].second << "\n";
            return 0;
        }
        if (vec[i].first + vec[j].first < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
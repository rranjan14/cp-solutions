#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
#define vlli vector<long long int>
using namespace std;
int main()
{
    lli n, m, k, count = 0;
    cin >> n >> m >> k;
    vlli applicants(n, 0);
    vlli apartments(m, 0);
    for (auto i = 0; i < n; i++)
    {
        cin >> applicants[i];
    }
    for (auto i = 0; i < m; i++)
    {
        cin >> apartments[i];
    }
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    lli i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(applicants[i] - apartments[j]) <= k)
        {
            count++;
            i++;
            j++;
        }
        else if (applicants[i] < apartments[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << count << "\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define lli long long int
using namespace std;
int main()
{
    lli n, a, b, ending_time = 0, count = 0;
    cin >> n;
    vector<pair<lli, lli>> timings(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a >> b;
        timings[i].first = b;
        timings[i].second = a;
    }
    sort(timings.begin(), timings.end());
    for (lli i = 0; i < n; i++)
    {
        if (timings[i].second >= ending_time)
        {
            ending_time = timings[i].first;
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}
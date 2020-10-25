#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    lli n, max_people = 0, a, b, count = 0;
    cin >> n;
    vector<pair<lli, bool>> timings;
    while (n--)
    {
        cin >> a >> b;
        timings.push_back({a, 1});
        timings.push_back({b, 0});
    }
    sort(timings.begin(), timings.end());
    for (int i = 0; i < timings.size(); i++)
    {
        count += timings[i].second ? 1 : -1;
        max_people = max(max_people, count);
    }
    cout << max_people << "\n";
    return 0;
}
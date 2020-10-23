#include <bits/stdc++.h>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define ppb pop_back
using namespace std;
typedef long long int ll;
vector<ll> v;
vector<ll> sum;
ll n;
void fin(ll pos, ll s)
{
    if (pos == n)
    {
        sum.pb(s);
        return;
    }
    fin(pos + 1, s + v[pos]);
    fin(pos + 1, s);
}
int main()
{
    // FastRead;
    ll t = 1;
    // cin>>t;
    while (t--)
    {
 
        cin >> n;
        v.resize(n, 0);
        ll s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s += v[i];
        }
        fin(0, 0);
        ll mi = LLONG_MAX;
        for (ll i = 0; i < sum.size(); i++)
        {
            mi = min(mi, abs(s - sum[i] - sum[i]));
        }
        cout << mi << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

void solve(){

    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=6;j++){
            if(j<=i)
                dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    cout << dp[n]<<"\n";
}

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
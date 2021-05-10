#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

void solve(){

    int n;
    cin >>n;
    int prev=INT_MIN;
    int ans = INT_MIN;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x>prev){
            prev=x;
            cnt++;
        }else{
            ans=max(ans,cnt);
            prev=x;
            cnt=1;
        }
    }
    ans = max(ans,cnt);
    cout << ans<<"\n";
}
int main(){
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 10;
vector<int> g[N];
int vis[N], act[N], dp[N][26];
string s;
int n, m, ans;
void dfs(int u)
{
    vis[u] = act[u] = 1;
    for (int v : g[u])
    {
        if (act[v])
        {
            puts("-1");
            exit(0);
        }
        if (!vis[v])
            dfs(v);
        for (int i = 0; i < 26; i++)
        {
            dp[u][i] = max(dp[u][i], dp[v][i]);
        }
    }
    dp[u][s[u] - 'a']++;
    for (int i = 0; i < 26; i++)
        ans = max(ans, dp[u][i]);
    act[u] = 0;
}
int main()
{
    cin >> n >> m >> s;
    s = "#" + s;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    cout << ans << "\n";
}

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
set<string> s;
void permute(string a, int l, int r)
{
    if (l == r)
        s.insert(a);
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    getline(cin, str);
    permute(str, 0, str.size() - 1);
    cout << s.size() << "\n";
    for (auto ele : s)
    {
        cout << ele << "\n";
    }
    return 0;
}
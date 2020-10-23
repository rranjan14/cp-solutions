#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#define li long int
using namespace std;
int main()
{
    string s;
    map<char, li> m;
    pair<char, li> p;
    vector<li> odd;
    getline(cin, s);
    for (li i = 0; i < (li)s.size(); i++)
    {
        m[s[i]] += 1;
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if (i->second & 1)
        {
            odd.push_back(i->first);
        }
    }
    if (odd.size() > 1)
        cout << "NO SOLUTION\n";
    else
    {
        string st = "", st1 = "";
        for (auto i = odd.begin(); i != odd.end(); i++)
        {
            p.first = *i;
            p.second = m[*i];
            m.erase(*i);
        }
        for (auto i = m.begin(); i != m.end(); i++)
        {
            for (li j = 0; j < (li)floor(i->second / 2); j++)
            {
                st += i->first;
            }
        }
        st1 = string(st.rbegin(), st.rend());
        if (odd.size() > 0)
            for (li i = 0; i < p.second; i++)
            {
                st += p.first;
            }
 
        st += st1;
        cout << st << "\n";
    }
    return 0;
}
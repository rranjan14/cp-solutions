#include <iostream>
#include <vector>
#define lli long long int
using namespace std;
void print(vector<lli> v)
{
    cout << v.size() << "\n";
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
}
int main()
{
    lli n;
    cin >> n;
    vector<lli> v1;
    vector<lli> v2;
    lli sum = ((n + 1) * n) / 2;
    if (n <= 2)
    {
        cout << "NO\n";
        exit(0);
    }
    if (n & 1)
    {
        if (sum & 1)
        {
            cout << "NO\n";
        }
        else
        {
            lli half_sum = sum / 2;
            lli s = 0;
            for (lli i = n; i > 0; i--)
            {
                s += i;
                if (s <= half_sum)
                    v1.push_back(i);
                else
                {
                    v2.push_back(i);
                    s -= i;
                }
            }
        }
        cout << "YES\n";
        print(v1);
        print(v2);
    }
    else
    {
        if (sum & 1)
        {
            cout << "NO\n";
        }
        else
        {
            lli start = 1;
            lli end = n;
            int turn = 0;
            while (start < end)
            {
                if (turn)
                {
                    v1.push_back(start);
                    v1.push_back(end);
                    turn = 0;
                }
                else
                {
                    v2.push_back(start);
                    v2.push_back(end);
                    turn = 1;
                }
                start++;
                end--;
            }
            cout << "YES\n";
            print(v1);
            print(v2);
        }
    }
    return 0;
}
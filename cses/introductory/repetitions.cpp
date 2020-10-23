#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    long long int count = 1;
    cin >> s;
    vector<long long int> vec(s.size());
    for (long long int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            count++;
        else
        {
            vec.push_back(count);
            count = 1;
        }
    }
    vec.push_back(count);
    cout << *max_element(vec.begin(), vec.end()) << "\n";
    return 0;
}
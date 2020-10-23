#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n, sum = 0;
    cin >> n;
    vector<long long int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    for (int i = 1; i < n; i++)
        if (vec[i] < vec[i - 1])
        {
            sum += vec[i - 1] - vec[i];
            vec[i] += vec[i - 1] - vec[i];
        }
    cout << sum << "\n";
    return 0;
}
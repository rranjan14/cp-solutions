#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int n;
    cin >> n;
    for (long int i = 1; i <= n; i++)
    {
        cout << ((i*i)*(i*i-1)/2)-4*(i-1)*(i-2) << "\n";
    }
}
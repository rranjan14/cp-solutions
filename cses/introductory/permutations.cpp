#include <iostream>
using namespace std;
int main()
{
    long long int n, c;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
    }
    else if (n == 4)
        cout << "2 4 1 3";
    else if (n > 3)
    {
        if (n & 1)
        {
            c = n - 1;
            while (n != 1)
            {
                cout << n << " ";
                n -= 2;
            }
            cout << n << " ";
            while (c != 2)
            {
                cout << c << " ";
                c -= 2;
            }
            cout << c << " ";
        }
        else
        {
            c = n - 1;
            while (n != 2)
            {
                cout << n << " ";
                n -= 2;
            }
            cout << n << " ";
            while (c != 1)
            {
                cout << c << " ";
                c -= 2;
            }
            cout << c << " ";
        }
        cout << "\n";
    }
    else
        cout << "NO SOLUTION\n";
    return 0;
}
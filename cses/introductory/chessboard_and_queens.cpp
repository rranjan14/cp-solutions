#include <iostream>
#include <string>
using namespace std;
int count = 0;
string board[8];
bool col[8], diag1[16], diag2[16];
void search(int r)
{
    if (r == 8)
    {
        count++;
        return;
    }
    for (int c = 0; c < 8; c++)
    {
        if (board[r][c] == '.')
        {
            if (col[c] || diag1[r + c] || diag2[c - r + 8 - 1])
                continue;
            col[c] = diag1[r + c] = diag2[c - r + 8 - 1] = true;
            search(r + 1);
            col[c] = diag1[r + c] = diag2[c - r + 8 - 1] = false;
        }
    }
}
int main()
{
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    search(0);
    cout << count;
}
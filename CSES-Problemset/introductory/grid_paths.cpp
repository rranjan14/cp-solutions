#include <iostream>
using namespace std;
bool visited[7][7];
int occupied[49];

void move(int r, int c, int &ans, int &steps)
{
    if (r == 7 - 1 && c == 0)
    {
        ans += (steps == 7 * 7 - 1);
        return;
    }
    if (((r + 1 == 7 || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < 7 && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < 7 && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == 7 || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < 7 && !visited[r - 1][c] && !visited[r + 1][c]) ||
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < 7 && !visited[r - 1][c] && !visited[r + 1][c]))
        return;

    visited[r][c] = 1;

    if (occupied[steps] != -1)
    {
        switch (occupied[steps])
        {
        case 0:
            if (r - 1 >= 0)
            {
                if (!visited[r - 1][c])
                {
                    steps++;
                    move(r - 1, c, ans, steps);
                    steps--;
                }
            }
            break;

        case 1:
            if (c + 1 < 7)
            {
                if (!visited[r][c + 1])
                {
                    steps++;
                    move(r, c + 1, ans, steps);
                    steps--;
                }
            }
            break;

        case 2:
            if (r + 1 < 7)
            {
                if (!visited[r + 1][c])
                {
                    steps++;
                    move(r + 1, c, ans, steps);
                    steps--;
                }
            }
            break;

        case 3:
            if (c - 1 >= 0)
            {
                if (!visited[r][c - 1])
                {
                    steps++;
                    move(r, c - 1, ans, steps);
                    steps--;
                }
            }
            break;
        }
        visited[r][c] = 0;
        return;
    }
    if (r - 1 >= 0)
    {
        if (!visited[r - 1][c])
        {
            steps++;
            move(r - 1, c, ans, steps);
            steps--;
        }
    }
    if (r + 1 < 7)
    {
        if (!visited[r + 1][c])
        {
            steps++;
            move(r + 1, c, ans, steps);
            steps--;
        }
    }
    if (c - 1 >= 0)
    {
        if (!visited[r][c - 1])
        {
            steps++;
            move(r, c - 1, ans, steps);
            steps--;
        }
    }
    if (c + 1 < 7)
    {
        if (!visited[r][c + 1])
        {
            steps++;
            move(r, c + 1, ans, steps);
            steps--;
        }
    }
    visited[r][c] = 0;
}

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '?')
            occupied[i] = -1;
        else if (str[i] == 'U')
            occupied[i] = 0;
        else if (str[i] == 'R')
            occupied[i] = 1;
        else if (str[i] == 'D')
            occupied[i] = 2;
        else if (str[i] == 'L')
            occupied[i] = 3;
    }
    int ans = 0, steps = 0;
    move(0, 0, ans, steps);
    cout << ans;
    return 0;
}
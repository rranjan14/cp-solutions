#include <bits/stdc++.h>

using namespace std;

int main()
{
    string secret, plainText, processedPlainText = "", cipheredText = "";
    cin >> secret;
    cin.ignore();
    getline(cin, plainText);

    vector<vector<char>> keySquare(5, vector<char>(5, ' '));
    map<char, int> hash;

    //processing and removing spaces from the plain text
    for (int i = 0; i < plainText.length(); i++)
        if (plainText[i] != ' ')
            processedPlainText += plainText[i];

    for_each(processedPlainText.begin(), processedPlainText.end(), [](char &c)
             { c = toupper(c); });

    int k = 0, x, y, i, j;

    //making 5x5 table for ciphering
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            while (hash[secret[k]] > 0 && k < secret.size())
                k++;
            if (k < secret.size())
            {
                keySquare[i][j] = secret[k];
                hash[secret[k]]++;
                x = i;
                y = j;
            }
            if (k == secret.size())
                break;
        }
        if (k == secret.size())
            break;
    }
    k = 0;
    for (; i < 5; i++)
    {
        for (; j < 5; j++)
        {
            while (hash[char(k + 'A')] > 0 && k < 26)
                k++;
            if (char(k + 'A') == 'J')
            {
                j--;
                k++;
                continue;
            }
            if (k < 26)
            {
                keySquare[i][j] = char(k + 'A');
                hash[char(k + 'A')]++;
            }
        }
        j = 0;
    }
    //breaking the processed plain text into pairs
    // for (i = 0; i < processedPlainText.length(); i++)
    // {
    //     if (processedPlainText[i] == processedPlainText[i + 1])
    //         processedPlainText.insert(processedPlainText.begin() + i + 1, 'X');
    // }

    //adding extra character to make the count of characters to be even
    if (processedPlainText.length() & 1)
        processedPlainText += 'X';

    map<char, pair<int, int>> hash2;

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            hash2[keySquare[i][j]] = {i, j};

    for (i = 0; i < processedPlainText.length() - 1; i += 2)
    {
        int row1 = hash2[processedPlainText[i]].first;
        int col1 = hash2[processedPlainText[i]].second;
        int row2 = hash2[processedPlainText[i + 1]].first;
        int col2 = hash2[processedPlainText[i + 1]].second;
        if (row1 == row2)
        {
            cipheredText += keySquare[row1][(col1 + 1) % 5];
            cipheredText += keySquare[row1][(col2 + 1) % 5];
        }
        else if (col1 == col2)
        {
            cipheredText += keySquare[(row1 + 1) % 5][col1];
            cipheredText += keySquare[(row2 + 1) % 5][col1];
        }
        else
        {
            cipheredText += keySquare[row1][col2];
            cipheredText += keySquare[row2][col1];
        }
    }

    cout << cipheredText << "\n";

    return 0;
}
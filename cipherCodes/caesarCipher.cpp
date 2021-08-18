#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    int shift;
    char str[100];
    string cipheredText="";
    cin >> shift;
    cin.ignore();
    cin.getline(str,sizeof(str));
    
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            cipheredText += " ";
        }
        else{
            if(isupper(str[i]))
                cipheredText = cipheredText + char(int(str[i] + shift - 65) % 26 + 65);
            else
                cipheredText = cipheredText + char(int(str[i] + shift - 97) % 26 + 97);
        }
    }
    
    cout << cipheredText << "\n";
    return 0;
}
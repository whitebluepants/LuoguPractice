#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int n = read();
    string s;
    cin >> s;
    string news = "";
    int j = 1;
    for(int i = 0;s[i] != '\0';)
    {
        news += s[i];
        i += j ++;
    }
    cout << news;

    return 0;
}
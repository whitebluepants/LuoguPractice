#include <stdio.h>
#include <string.h>
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
int a[26];
int main()
{
    char s[1005] = {};
    // string s;
    cin.getline(s,1024);
    // getline(cin,s);
    
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            a[s[i] - 'A'] ++;
        }
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            a[s[i] - 'a'] ++;
        }
    }
    int max = -1,ch = 0;

    for(int i = 0;i < 26;i ++)
    {
        if(a[i] > max)
        {
            max = a[i];
            ch = i;
        }
    }
    printf("%c %d",'a' + ch,max);

    return 0;
}
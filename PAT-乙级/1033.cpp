#include <stdio.h>
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
int f[200];
int main()
{
    int flag = 0;
    char s[100001] = {};

    cin.getline(s,100001);  // 第一行可能会为空 不能用scanf
    
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            f[s[i] + 32] = 1;
        }
        else
        {
            f[s[i]] = 1;
        }
    }
    cin.getline(s,100001);

    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z' && (f['+'] == 1 || f[s[i] + 32] == 1)) 
        {
            continue;
        }
        if(f[s[i]] == 1)
        {
            continue;
        }
        printf("%c",s[i]);
        flag = 1;
    }
    if(!flag)
    {
        printf("\n");
    }
    return 0;
}
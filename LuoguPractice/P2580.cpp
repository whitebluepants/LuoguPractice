#include <stdio.h>
#include <map>
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
int main()
{
    int n = read();
    map<string,int> m;

    for(int i = 0;i < n;i ++)
    {
        string s;
        cin >> s;
        m[s] = 1;
    }
    
    int mm = read();
    for(int i = 0;i < mm;i ++)
    {
        string s;
        cin >> s;
        if(m[s] == 0)
        {
            printf("WRONG\n");
        }
        else if(m[s] == 1)
        {
            printf("OK\n");
            m[s] ++;
        }
        else
        {
            printf("REPEAT\n");
        } 
    }
    return 0;
}
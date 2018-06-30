#include <stdio.h>
#include <map>
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
    char s1[101] = {},s2[101] = {};
    char p1[101] = {};
    map<char,char> m;
    int f[26] = {};

    scanf("%s %s %s",s1,s2,p1);
    int flag = 0;
    for(int i = 0;s1[i] != '\0';i ++)
    {
        if(m[s1[i]] != 0 && m[s1[i]] != s2[i])
        {
            flag = 1;
            break;
        }
        else if(m[s1[i]] != s2[i] && f[s2[i] - 'A'] != 0)
        {
            flag = 1;
            break;
        }    
        else if(m[s1[i]] == s2[i])
        {
            continue;
        }
        else
        {
            m[s1[i]] = s2[i];
            f[s2[i] - 'A'] = 1;
        }
    }
    for(int i = 0;i < 26;i ++)
    {
        if(f[i] == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Failed");
    }
    else
    {
        for(int i = 0;p1[i] != '\0';i ++)
        {
            printf("%c",m[p1[i]]);
        }
    }
    return 0;
}
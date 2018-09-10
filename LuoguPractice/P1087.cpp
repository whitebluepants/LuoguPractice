#include <stdio.h>
#include <string.h>
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
char s[1025] = {};
void erfen(int begin,int end)
{
    int flag = -1;
    for(int i = begin;i < end - 1;i ++)
    {
        if(s[i] != s[i + 1])
        {
            flag = 2;
            break;
        }
    }
    int mid = (begin + end) / 2;
    if(begin != mid)
    {
        erfen(begin,mid);
        erfen(mid,end);
    }
    if(flag != 2)
    {
        if(s[begin] == '1')
        {
            printf("I");
        }
        else
        {
            printf("B");
        }
    }
    else
    {
        printf("F");
    }
}
int main()
{
    int n = read();
    scanf("%s",s);

    int len = strlen(s);
    erfen(0,len);
    
    return 0;
}
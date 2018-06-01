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
char s[10001];
char ss[10001];
int len,num;
void erfen(int begin,int end)
{
    int flag = 0;
    for(int i = begin + 1;i < end;i ++)
    {
        if(s[i] != s[i - 1])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        if(s[begin] == '0')
        {
            ss[num] = 'A';
        }
        else
        {
            ss[num] = 'B';
        }
        num ++;
        return;
    }

    int mid = (begin + end) / 2;
    ss[num ++] = 'C';
    erfen(begin,mid);
    erfen(mid,end);
}
int main()
{
    scanf("%s",s);
    len = strlen(s);
    int flag = 0;
    for(int i = 0;i < len;i ++)
    {
        if(s[i] != '0')
        {   
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("A");
        return 0;
    }
    flag = 0;
    for(int i = 0;i < len;i ++)
    {
        if(s[i] != '1')
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("B");
        return 0;
    }

    erfen(0,len);
    printf("%s",ss);

    return 0;
}
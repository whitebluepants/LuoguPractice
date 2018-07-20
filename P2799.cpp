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
char s[100001];
void binary(char s[],int begin,int end)
{
    int mid = (begin + end) / 2;
    char s1[50001] = {}, s2[50001] = {};
    int j = 0;
    for(int i = 0;i <= mid;i ++)
    {
        s1[i] = s[begin + i];
        s2[i] = s[mid + 1 + i];
    }
    int flag = 0;
    for(int i = 0;i <= mid;i ++)
    {
        if(s2[i] != s1[mid - i])
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        binary(s1,begin,mid);
    }
    else
    {
        printf("%d",strlen(s));
    }
}
int main()
{
    scanf("%s",s);
    int len = strlen(s);

    binary(s,0,len - 1);

    return 0;
}
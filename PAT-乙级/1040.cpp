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
/*
    一直记录P的数量 碰到A以后记录该A之前的P数量 并记录A的位置
    当找到T后 遍历该T之前的所有A 增加数量 为P
*/
char s[100005];
long long count = 0;
int main()
{
    scanf("%s",s);
    int k = 0;
    int p = 0;
    int t = 0;
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] == 'P')
        {
            p ++;
        }
        if(s[i] == 'A')
        {
            t += p;
        }
        if(s[i] == 'T')
        {
            count += t;
            count %= 1000000007;
        }
    }
    printf("%lld",count);

    return 0;
}
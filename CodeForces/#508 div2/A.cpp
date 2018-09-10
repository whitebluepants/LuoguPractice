#include <stdio.h>
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
int num[27];
char s[100001];
int main()
{
    int n = read(),k = read();
    int minn = 999999999;
    scanf("%s",s);

    for(int i = 0;i < n;i ++)
    {
        num[s[i] - 'A'] ++;
    }

    for(int i = 0;i < k;i ++)
    {
        if(num[i] < minn)
        {
            minn = num[i];
        }
    }

    minn *= k;

    printf("%d",minn);

    return 0;
}
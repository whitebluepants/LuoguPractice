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
int grade[101];
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        grade[t] ++;
    } 

    int k = read();
    for(int i = 0;i < k;i ++)
    {
        int t = read();
        printf("%d",grade[t]);
        if(i != k - 1)
        {
            printf(" ");
        }
    }

    return 0;
}
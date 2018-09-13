#include <stdio.h>
#include <algorithm>
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
struct node
{
    char s[81];
};
node ans[101];
int main()
{
    int i = 0;

    while(scanf("%s",ans[i].s) != EOF)
    {
        i ++;
    }

    reverse(ans,ans + i);

    for(int j = 0;j < i;j ++)
    {
        printf("%s",ans[j].s);
        if(j != i - 1)
        {
            printf(" ");
        }
    }
    return 0;
}
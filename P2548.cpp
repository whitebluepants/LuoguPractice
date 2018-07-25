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
struct ad
{
    char s[2][11];
    int count[2];
};
ad ans[1000];
int main()
{
    int n = read(),m = read();   
    
    for(int i = 0;i < m;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            char s[11] = {};
            scanf("%s",s);
            
            if(ans[j].count[0] == 0 && ans[j].count[1] == 0)
            {
                strcpy(ans[j].s[0],s);
                ans[j].count[0] ++;
            }
            else if(strcmp(ans[j].s[0],s) != 0)
            {
                strcpy(ans[j].s[1],s);
                ans[j].count[1] ++;
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        if(ans[i].count[1] == 0)
        {
            printf("%s",ans[i].s[0]);
        }
        else
        {
            printf("*");
        }
        if(i != n - 1)
        {
            printf(" ");
        }
    }

    return 0;
}
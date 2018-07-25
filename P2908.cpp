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
int main()
{
    int n = read(),m = read();
    char s[1001][1001] = {};
    char ss[100][31] = {};

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }
    for(int i = 0;i < m;i ++)
    {
        scanf("%s",ss[i]);
    }
    
    for(int i = 0;i < n;i ++)
    {
        int count = 0;
        for(int k = 0;k < m;k ++)
        {
            int l = 0;
            for(int j = 0;s[i][j] != '\0';j ++)
            {
                if(s[i][j] == ss[k][l] || s[i][j] == ss[k][l] + ('a' - 'A') || s[i][j] == ss[k][l] - ('a' - 'A'))
                {
                    l ++;
                }
                if(ss[k][l] == '\0')
                {
                    count ++;
                    break;
                }
            }
        }
        printf("%d\n",count);
    }

    return 0;
}
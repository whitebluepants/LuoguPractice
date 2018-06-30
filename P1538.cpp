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
char ans[300][14000];
char s[256];
int k;
void d(int p,int top,int topleft,int topright,int mid,int bottomleft,int bottomright,int bottom)
{
    for(int i = 0;i < 2 * k + 3;i ++)
    {
        for(int j = p;j <= p + 2 + k;j ++)
        {
            ans[i][j] = ' ';
        }
    }

    for(int i = 1;i <= k;i ++)
    {
        if(topleft)
        {
            ans[i][p] = '|';
        }
        if(topright)
        {
            ans[i][p + k + 1] = '|';
        }
    }

    for(int i = k + 2;i <= 2 * k + 2 - 1;i ++)
    {
        if(bottomleft)
        {
            ans[i][p] = '|';
        }
        if(bottomright)
        {
            ans[i][p + k + 1] = '|';
        }
    }    

    for(int i = p + 1;i <= p + k;i ++)
    {
        if(mid)
        {
            ans[1 + k][i] = '-';
        }
        if(top)
        {
            ans[0][i] = '-';
        }
        if(bottom)
        {
            ans[2 * k + 2][i] = '-';
        }
    }
}
int main()
{
    k = read();
    scanf("%s",s);
    int j = 0;
    for(int i = 0;s[i] != '\0';i ++)
    {
        switch(s[i])
        {
            case '0': d(j,1,1,1,0,1,1,1); break;
            case '1': d(j,0,0,1,0,0,1,0); break;
            case '2': d(j,1,0,1,1,1,0,1); break;
            case '3': d(j,1,0,1,1,0,1,1); break;
            case '4': d(j,0,1,1,1,0,1,0); break;
            case '5': d(j,1,1,0,1,0,1,1); break;
            case '6': d(j,1,1,0,1,1,1,1); break;
            case '7': d(j,1,0,1,0,0,1,0); break;
            case '8': d(j,1,1,1,1,1,1,1); break;
            case '9': d(j,1,1,1,1,0,1,1); break;
        }
        j += k + 3;
    }
    for(int i = 0;i < 3 + k * 2;i ++)
    {
        printf("%s\n",ans[i]);
    }

    return 0;
}
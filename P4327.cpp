#include <stdio.h>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9')if(ch == '-')f = 0;ch = getchar();
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
char s[16];
char ans[5][80];
void spell(int b,char s,char t)
{
    for(int i = 0;i < 5;i ++)
    {
        if(i == 2)
        {
            if(ans[2][b] == '*')
            {
                ans[2][b + 4] = t;
            }
            else
            {
                ans[2][b] = t;
                ans[2][b + 4] = t;
            }
        }
        else
        {
            ans[i][b] = '.';
            ans[i][b + 4] = '.';
        }        
    }
    for(int i = 0;i < 5;i ++)
    {
        if(i == 1 || i == 3)
        {
            ans[i][b + 1] = ans[i][b + 3] = t;
        }
        else
        {
            ans[i][b + 1] = ans[i][b + 3] = '.';
        }
    }
    for(int i = 0;i < 5;i ++)
    {
        if(i == 0 || i == 4)
        {
            ans[i][b + 2] = t;
        }
        else if(i == 1 || i == 3)
        {
            ans[i][b + 2] = '.';
        }
        else
        {
            ans[i][b + 2] = s;
        }
    }
}
int main()
{
    scanf("%s",s);

    for(int i = 0,j = 0;s[i] != '\0';i ++,j ++)
    {
        if(j == 2)
        {
            j = -1;
            spell(i * 4,s[i],'*');
        }   
        else
        {
            spell(i * 4,s[i],'#');
        } 
    }
    for(int i = 0;i < 5;i ++)
    {
        printf("%s\n",ans[i]);
    }

    return 0;
}
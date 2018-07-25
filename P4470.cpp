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
char s[50][101];
int main()
{
    int n = read();
    
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s[i]);
    }
    
    char ss[101] = {};
    scanf("%s",ss);

    char ans[4][9] = {};
    for(int i = 0;i < 4;i ++)
    {
        for(int j = 0;j < 8;j ++)
        {
            ans[i][j] = '*';
        }
    }
    
    int letter[26] = {};
    for(int i = 0;i < n;i ++)
    {
        int flag = 0,j;
        for(j = 0;ss[j] != '\0';j ++)
        {
            if(s[i][j] != ss[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            letter[s[i][j] - 'A'] = 1;
        }
    }
    
    for(int i = 0;i < 26;i ++)
    {
        if(letter[i] == 1)
        {
            char t = 'A' + i;

            if(t >= 'A' && t <= 'E')
            {
                ans[0][3 + (t - 'A')] = t;
            }
            if(t >= 'F' && t <= 'M')
            {
                ans[1][t - 'F'] = t;
            }
            if(t >= 'N' && t <= 'U')
            {
                ans[2][t - 'N'] = t;
            }
            if(t >= 'V' && t <= 'Z')
            {
                ans[3][t - 'V'] = t;
            }
        }
    }

    for(int i = 0;i < 4;i ++)
    {
        printf("%s\n",ans[i]);
    }

    return 0;
}
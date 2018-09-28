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
char s[10001];
int ans[6];
int main()
{
    scanf("%s",s);

    for(int i = 0;s[i] != '\0';i ++)
    {
        switch(s[i])
        {
            case 'P': ans[0] ++; break;
            case 'A': ans[1] ++; break;
            case 'T': ans[2] ++; break;
            case 'e': ans[3] ++; break;
            case 's': ans[4] ++; break;
            case 't': ans[5] ++;
        }
    }
    int max = -1;
    for(int i = 0;i < 6;i ++)
    {
        if(ans[i] > max)
        {
            max = ans[i];
        }
    }

    for(int i = 0;i < max;i ++)
    {
        for(int j = 0;j < 6;j ++)
        {
            if(ans[j])
            {
                switch(j)
                {
                    case 0: printf("P"); break;
                    case 1: printf("A"); break;
                    case 2: printf("T"); break;
                    case 3: printf("e"); break;
                    case 4: printf("s"); break;
                    case 5: printf("t");
                }
                ans[j] --;
            }
        }
    }

    return 0;
}
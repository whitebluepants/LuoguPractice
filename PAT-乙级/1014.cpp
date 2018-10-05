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
int l[26];
int u[26];
int main()
{
    char s[4][61] = {};
    char w,t;
    for(int i = 0;i < 4;i ++)
    {
        scanf("%s",s[i]);
    }

    int l1 = strlen(s[0]), l2 = strlen(s[1]);

    int f1 = 0;
    for(int i = 0;i < l1 && i < l2;i ++)
    {
        if(s[0][i] == s[1][i])
        {
            if(f1 == 0 && s[0][i] >= 'A' && s[0][i] <= 'G')
            {
                w = s[0][i];
                f1 = 1;
            }
            else if(f1 == 1 && ((s[0][i] >= '0' && s[0][i] <= '9') || (s[0][i] >= 'A' && s[0][i] <= 'N')))
            {
                t = s[0][i];
                break; // 卡了一个点 需要break
            }
        }
    }   
    int l3 = strlen(s[2]), l4 = strlen(s[3]);
    int min = 0;
    for(int i = 0;i < l3 && i < l4;i ++)
    {
        if(s[2][i] == s[3][i] && ((s[2][i] >= 'a' && s[2][i] <= 'z') || (s[2][i] >= 'A' && s[2][i] <= 'Z')))
        {
            min = i;
            break;
        }
    }
    char ss[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

    printf("%s ",ss[w - 'A']);
    if(t >= '0' && t <= '9')
    {
        printf("%02d:",t - '0');
    }
    else
    {
        printf("%d:",10 + t - 'A');
    }

    printf("%02d",min);

    return 0;
}
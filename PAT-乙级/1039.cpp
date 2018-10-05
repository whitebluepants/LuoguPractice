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
char s1[1001];
char s2[1001];
int ans1[200];
int ans2[200];
int main()
{
    scanf("%s %s",s1,s2);

    for(int i = 0;s1[i] != '\0';i ++)
    {
        ans1[s1[i]] ++;
    }
    for(int i = 0;s2[i] != '\0';i ++)
    {
        ans2[s2[i]] ++;
    }

    int len1 = strlen(s1), len2 = strlen(s2);
    int more = len1 - len2,less = 0;
    int flag = 0;

    for(int i = 0;i < 'z' + 1;i ++)
    {
        if(ans2[i] != '0')
        {
            if(ans2[i] > ans1[i])
            {
                flag = 1;
                less += ans2[i] - ans1[i];
            }
        }
    }

    if(flag)
    {
        printf("No %d",less);
    }
    else
    {
        printf("Yes %d",more);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    char s1[1000] = {},s2[1000] = {};
    int a[1000] = {},b[1000] = {},c[1000] = {};

    scanf("%s %s",s1,s2);

    int n1 = strlen(s1),n2 = strlen(s2);
    int m1,m2;
    for(int i = 0;i < n1;i ++)
    {
        if(s1[i] != '0' && s1[i] != NULL)
        {
            m1 = i;
            break;
        }
        else if(s1[i] == '0' && i == n1 - 1)
        {
            m1 = 0;
            n1 = 1;
            break;
        }
    }
    for(int i = 0;i < n2;i ++)
    {
        if(s2[i] != '0' && s2[i] != NULL)
        {
            m2 = i;
            break;
        }
        else if(s2[i] == '0' && i == n2 - 1)
        { 
            m2 = 0;
            n2 = 1;
            break;
        }
    }

    for(int i = n1 - 1,j = 0;i >= m1;i --,j ++)
    {
        a[j] = s1[i] - '0';
    }
    for(int i = n2 - 1,j = 0;i >= m2;i --,j ++)
    {
        b[j] = s2[i] - '0';
    }

    int len = max(n1-m1,n2-m2);
    
    for(int i = 0;i < len;i ++)
    {
        c[i] = a[i] + b[i] + c[i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
    }
    if(c[len] == 0)
    {
        len --;
    }
    for(int i = len;i >= 0;i --)
    {
        printf("%d",c[i]);
    }

    return 0;
}
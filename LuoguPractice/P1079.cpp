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
int main()
{
    char s1[101] = {};
    char s2[1001] = {};
    scanf("%s %s",s1,s2);
    int len = strlen(s1);
    int j = 0;
    for(int i = 0;s2[i] != '\0';i ++)
    {
        int temp = s1[j ++];
        if(j >= len)
        {
            j = 0;
        }
        if(temp >= 'A' && temp <= 'Z')
        {
            temp = temp - 'A';
        }
        else if(temp >= 'a' && temp <= 'z')
        {
            temp = temp - 'a';
        }
        if(s2[i] >= 'A' && s2[i] <= 'Z')
        {
            s2[i] -= temp;
            if(s2[i] < 'A')
            {
                s2[i] += 26;
            }
        }
        if(s2[i] >= 'a' && s2[i] <= 'z')
        {
            s2[i] -= temp;
            if(s2[i] < 'a')
            {
                s2[i] += 26;
            }
        }
    }
    printf("%s",s2);

    return 0;
}
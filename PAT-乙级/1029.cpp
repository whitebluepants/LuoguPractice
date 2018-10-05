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
int flag[1000];
char s1[81];
char s2[81];
int main()
{
    scanf("%s %s",s1,s2);
    int len1 = strlen(s1), len2 = strlen(s2);

    int i = 0,j = 0;
    while(i != len1 - 1)
    {
        if(s1[i] != s2[j])
        {
            if(s1[i] >= 'A' && s1[i] <= 'Z')
            {
                if(!flag[s1[i]])
                {
                    flag[s1[i]] = 1;
                    printf("%c",s1[i]);
                }
            }
            if(s1[i] >= 'a' && s1[i] <= 'z')
            {
                char ch = s1[i] - 32;
                if(!flag[ch])
                {
                    flag[ch] = 1;
                    printf("%c",ch);
                }
            }
            if(s1[i] >= '0' && s1[i] <= '9')
            {
                if(!flag[s1[i]])
                {
                    flag[s1[i]] = 1;
                    printf("%c",s1[i]);
                }
            }
            if(s1[i] == '_')
            {
                if(!flag[s1[i]])
                {
                    flag[s1[i]] = 1;
                    printf("%c",s1[i]);
                }
            }
            i ++;
        }
        else
        {
            i ++;
            j ++;
        }
    }
    return 0;
}
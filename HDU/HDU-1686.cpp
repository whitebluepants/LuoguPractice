#include <string.h>
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
char pattern[10010];
char s[1000010];
int match[10010];
void buildMatch(char pattern[],int m)
{
    int i;
    match[0] = -1;

    for(int j = 1;j < m;j ++)
    {
        i = match[j - 1];
        while(i >= 0 && pattern[i + 1] != pattern[j])
        {
            i = match[i];
        }

        if(pattern[i + 1] == pattern[j])
        {
            match[j] = i + 1;
        }
        else
        {
            match[j] = -1;
        }
    }
}
void kmp(char s[],char pattern[])
{
    int n = strlen(s);
    int m = strlen(pattern);
    
    if(n < m)
    {
        printf("0\n");
        return ;
    }

    int i = 0,j = 0;
    buildMatch(pattern,m);
    
    int count = 0;
    while(i < n)
    {
        if(s[i] == pattern[j])
        {
            i ++;
            j ++;
        }
        else if(j > 0)
        {
            j = match[j - 1] + 1;
        }
        else
        {
            i ++;
        }

        if(j == m)
        {
            count ++; // 不需要 i--和j=0 i--会卡主串全同一字符
        }
    }

    printf("%d\n",count);
}
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        scanf("%s %s",pattern,s);

        kmp(s,pattern);
    }

    return 0;
}
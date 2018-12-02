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
char s[1000010];
char pattern[1000010];
int match[1000010];
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
    
    buildMatch(pattern,m);
    int i = 0,j = 0;

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
            printf("%d\n",i - m + 1);
            i --;
            j = 0;
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);

    scanf("%s %s",s,pattern);

    kmp(s,pattern);

    int j = strlen(pattern);

    for(int i = 0;i < j;i ++)
    {
        printf("%d ",match[i] + 1);
    }

    return 0;
}
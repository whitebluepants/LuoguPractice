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
char s[1010];
char pattern[1010];
int match[1010];
void buildMatch(char s[],int m)
{
    int i = 0;
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

    int i = 0,j = 0,count = 0;
    buildMatch(pattern,m);

    while(i < n)
    {
        if(s[i] == pattern[j])
        {
            i ++;
            j ++;
        }
        else if(j > 0)
        {
            j = match[j] + 1;
        }
        else
        {
            i ++;
        }

        if(j == m)
        {
            count ++;
            j = 0;
        }
    }
    printf("%d\n",count);
}
int main()
{
	// freopen("in.txt","r",stdin);
    scanf("%s",s);

    while(s[0] != '#')
    {
        scanf("%s",pattern);
        kmp(s,pattern);
        scanf("%s",s);
    }

    return 0;
}
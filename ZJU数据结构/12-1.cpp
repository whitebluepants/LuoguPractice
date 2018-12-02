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
char pattern[100010];
int match[100010];
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
int kmp(char s[],char pattern[])
{
    int n = strlen(s);
    int m = strlen(pattern);
    int i = 0,j = 0;
    if(n < m)
    {
        return -1;
    }

    buildMatch(pattern,m);

    while(i < n && j < m)
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
            j = 0;
            i ++; // 此处不是 j = 0
        }
    }

    return j == m ? i - m : -1;
}
int main()
{
	// freopen("in.txt","r",stdin);
	
    scanf("%s",s);
    int n = read();
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",pattern);

        int p = kmp(s,pattern);
        if(p == -1)
        {
            printf("Not Found\n");
        }
        else
        {
            printf("%s\n",s + p);
        }

        // char *ans = strstr(s,pattern);
        // if(ans == NULL)
        // {
        //     printf("Not Found\n");
        // }
        // else
        // {
        //     printf("%s\n",ans);
        // }
    }

    return 0;
}
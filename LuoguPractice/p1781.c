#include <string.h>
#include <stdio.h>
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int ans[20] = {};
void qsort(char s[][101],int begin,int end)
{
    if(begin >= end)
    {
        return ;
    }
    int i = begin,j = end;
    char ss[101];
    strcpy(ss,s[(begin + end) / 2]);
    int mid = strlen(ss);

    while(i <= j)
    {
        while(strlen(s[i]) > mid)
        {
            i ++;
        }
        while(strlen(s[j]) < mid)
        {
            j --;
        }
        if(i <= j)
        {
            char temp[101];
            strcpy(temp,s[i]);
            strcpy(s[i],s[j]);
            strcpy(s[j],temp);
            swap(&ans[i],&ans[j]);
            i ++;
            j --;
        }
    }
    if(begin < j)
    {
        qsort(s,begin,j);
    }
    if(end > i)
    {
        qsort(s,i,end);
    }
}
void qsort2(char s[][101],int begin,int end)
{
    if(begin >= end)
    {
        return ;
    }
    int i = begin,j = end;
    char ss[101];
    strcpy(ss,s[(begin + end) / 2]);

    while(i <= j)
    {
        while(strcmp(s[i],ss) > 0)
        {
            i ++;
        }
        while(strcmp(s[j],ss) < 0)
        {
            j --;
        }
        if(i <= j)
        {
            char temp[101];
            strcpy(temp,s[i]);
            strcpy(s[i],s[j]);
            strcpy(s[j],temp);
            swap(&ans[i],&ans[j]);
            i ++;
            j --;
        }
    }
    if(begin < j)
    {
        qsort2(s,begin,j);
    }
    if(end > i)
    {
        qsort2(s,i,end);
    }
}
int main()
{
    char s[20][101] = {};
    int n = read();
    for(int i = 0;i < n;i ++)
    {
        ans[i] = i + 1;
        scanf("%s",s[i]);
    }
    qsort(s,0,n - 1);
    int len = strlen(s[0]);
    for(int i = 0;i < n;i ++)
    {
        if(strlen(s[i]) < len)
        {
            s[i][0] = '\0';
        }
    }
    qsort2(s,0,n - 1);
    printf("%d\n%s",ans[0],s[0]);

    return 0;
}
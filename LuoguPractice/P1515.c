#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int ans[30] = {0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
int a,b;
int len = 14;
int count = 0;
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void qsort(int a[],int begin,int end)
{
    if(begin >= end)
    {
        return ;
    }
    int i = begin,j = end;
    int mid = a[(begin + end) / 2];

    while(i <= j)
    {
        while(a[i] < mid)
        {
            i ++;
        }
        while(a[j] > mid)
        {
            j --;
        }
        if(i <= j)
        {
            swap(&a[i],&a[j]);
            i ++;
            j --;
        }
    }
    if(begin < j)
    {
        qsort(a,begin,j);
    }
    if(end > i)
    {
        qsort(a,i,end);
    }
}
void dfs(int i)
{
    if(i == len - 1)
    {
        count ++;
    }

    for(int j = i + 1;j < len;j ++)
    {
        if(ans[j] - ans[i] >= a && ans[j] - ans[i] <= b)
        {
            dfs(j);
        }
    }

}
int main()
{
    a = read(),b = read();
    int n = read(); 
    len += n;

    for(int i = 0,j = 14;i < n;i ++)
    {
        ans[j ++] = read();
    }

    qsort(ans,0,14 + n - 1);

    dfs(0);

    printf("%d",count);

    return 0;
}
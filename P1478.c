#include <stdio.h>
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    return f?x:x*-1;
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void qsort(int a[][2],int begin,int end)
{
    if(begin >= end)
    {
        return;
    }
    int i = begin,j = end;
    int mid = a[(begin + end) / 2][1];
    
    while(i <= j)
    {
        while(a[i][1] < mid)
        {
            i ++;
        }
        while(a[j][1] > mid)
        {
            j --;
        }
        if(i <= j)
        {
            swap(&a[i][1],&a[j][1]);
            swap(&a[i][0],&a[j][0]);
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
int main()
{
    int count = 0;
    int n = read(),s = read(),a = read(),b = read();
    int ans[5000][2];
    for(int i = 0;i < n;i ++)
    {
        ans[i][0] = read(),ans[i][1] = read();
    }
    qsort(ans,0,n - 1);
    
    for(int i = 0;i < n;i ++)
    {
        if(ans[i][0] <= (a + b) && ans[i][1] <= s)
        {
            count ++;
            s -= ans[i][1];
        }
    }
    printf("%d",count);

    return 0;
}
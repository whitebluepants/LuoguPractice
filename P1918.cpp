#include <stdio.h>
#include <algorithm>
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
int ans[100001][2];
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
        return ;
    }
    int i = begin,j = end;
    int mid = a[(begin + end) / 2][0];
    while(i <= j)
    {
        while(a[i][0] < mid)
        {
            i ++;
        }
        while(a[j][0] > mid)
        {
            j --;
        }
        if(i <= j)
        {
            swap(&a[i][0],&a[j][0]);
            swap(&a[i][1],&a[j][1]);
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
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        ans[i][0] = read(),ans[i][1] = i;
    }
    qsort(ans,1,n);

    int m = read();
    for(int i = 0;i < m;i ++)
    {
        int temp = read();
        
        int a = 1,b = n,flag = 0;
        while(a <= b)
        {
            int m = (a + b) / 2;
            int mid = ans[m][0];
            if(mid == temp)
            {
                flag = ans[m][1];
                break;
            }
            if(mid > temp)
            {
                b = m - 1;
            }
            if(mid < temp)
            {
                a = m + 1;
            }
        }
        printf("%d\n",flag);
    }

    return 0;
}
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
int a[1001];
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
int main()
{
    int n = read(),l = read();
    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }

    qsort(a,0,n - 1);

    int leftd = a[0] - 0;
    int rightd = l - a[n - 1];
    int maxedge = leftd > rightd? leftd : rightd;

    int dis = 0;

    for(int i = 1;i < n;i ++)
    {
        if(a[i] - a[i - 1] > dis)
        {
            dis = a[i] - a[i - 1];
        }
    }

    if(dis / 2 < maxedge)
    {
        dis = maxedge;
        printf("%f",1.0 * dis);
    }
    else
    {
        printf("%f",1.0 * dis / 2);
    }
    
    return 0;
}
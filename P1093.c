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
        while(a[i][0] > mid)
        {
            i ++;
        }
        while(a[j][0] < mid)
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
    int a[301][3] = {};
    int b[301][2] = {};
    for(int i = 0;i < n;i ++)
    {
        a[i][0] = read(),a[i][1] = read(),a[i][2] = read();
        b[i][0] = (a[i][0] + a[i][1] + a[i][2]);
        b[i][1] = i;
    }

    qsort(b,0,n - 1);

    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(b[j][0] == b[j + 1][0])
            {
                if(a[b[j][1]][0] < a[b[j + 1][1]][0])
                {
                    swap(&b[j][1],&b[j + 1][1]);
                }
                else if(a[b[j][1]][0] == a[b[j + 1][1]][0])
                {
                    if(b[j][1] > b[j + 1][1])
                    {
                        swap(&b[j][1],&b[j + 1][1]);
                    }
                }
            }
        }
    }
    for(int i = 0;i < 5;i ++)
    {
        printf("%d %d\n",b[i][1] + 1,b[i][0]);
    }
    return 0;
}
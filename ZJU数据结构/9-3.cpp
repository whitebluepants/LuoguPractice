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
int a[101];
int b[101];
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        a[i] = read();
    }
    for(int i = 0;i < n;i ++)
    {
        b[i] = read();
    }
    
    int i,j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; a[j] == b[j] && j < n; j++);
    
    if(j == n)
    {
        printf("Insertion Sort\n");
        sort(a,a + i + 2);
        int flag = 0;
        for(int i = 0;i < n;i ++)
        {
            if(flag)
            {
                printf(" ");
            }
            printf("%d",a[i]);
            flag = 1;
        }
    }
    else
    {
        printf("Heap Sort\n");

        int N = n - 1;
        for(int j = n - 1;j - 1 >= 0;j --)
        {
            if(b[j] >= b[j - 1])
            {
                N --;
            }
            else
            {
                break;
            }
        }

        int temp = b[0];
        b[0] = b[N];
        b[N] = temp;

        int parent,child;
        int x = b[0];

        for(parent = 0;parent * 2 + 1 < N;parent = child)
        {
            child = parent * 2 + 1;
            if(child != N - 1 && b[child] < b[child + 1])
            {
                child ++;
            }
            if(x >= b[child])
            {
                break;
            }
            b[parent] = b[child];
        }
        b[parent] = x;

        int flag = 0;
        for(int i = 0;i < n;i ++)
        {
            if(flag)
            {
                printf(" ");
            }
            printf("%d",b[i]);
            flag = 1;
        }
    }

    return 0;
}
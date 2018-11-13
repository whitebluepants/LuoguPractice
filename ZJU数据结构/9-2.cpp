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
int n;
int a[101] = {},b[101] = {};
int main()
{
    n = read();

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
    }
    else
    {
        printf("Merge Sort\n");
        
        int flag = 1,k = 1;

        while(flag)
        {
            flag = 0;
            for(int i = 0;i < n;i ++)
            {
                if(a[i] != b[i])
                {
                    flag = 1;
                    break;
                }
            }
            k *= 2;

            for(int i = 0;i < n / k;i ++)
            {
                sort(a + (i) * k,a + (i + 1) * k);
            }
            sort(a + n / k * k,a + n);
        }
    }

    int f = 0;
    for(int i = 0;i < n;i ++)
    {
        if(f)
        {
            printf(" ");
        }
        printf("%d",a[i]);
        f = 1;
    }

    return 0;
}
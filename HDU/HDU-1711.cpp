#include <stdio.h>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){x = x * 10 + ch - '0';ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int a1[1000001];
int a2[10001];
int match[10001];
void buildMatch(int m)
{
    int i;
    match[0] = -1;

    for(int j = 1;j < m;j ++)
    {
        i = match[j - 1];
        while(i >= 0 && a2[j] != a2[i + 1])
        {
            i = match[i];
        }

        if(a2[i + 1] == a2[j])
        {
            match[j] = i + 1;
        }
        else
        {
            match[j] = -1;
        }
    }
}
int main()
{
    int t = read();

    for(int i = 0;i < t;i ++)
    {
        int n = read(),m = read();

        for(int j = 0;j < n;j ++)
        {
            a1[j] = read();
        }
        for(int j = 0;j < m;j ++)
        {
            a2[j] = read();
        }
        
        buildMatch(m);

        int a = 0,b = 0;
        while(a < n && b < m)
        {
            if(a1[a] == a2[b])
            {
                a ++;
                b ++;
            }
            else if(b > 0)
            {
                b = match[b - 1] + 1;
            }
            else
            {
                a ++;
            }
        }

        if(b == m)
        {
            printf("%d\n",a - m + 1);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
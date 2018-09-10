#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int x = 0;
    int f = 1;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
int main()
{
    int a[3];
    a[0] = read(),a[1] = read(),a[2] = read();
    sort(a,a + 3);
    char s[4] = {};
    scanf("%s",s);
    for(int i = 0;s[i] != '\0';i ++)
    {
        if(s[i] == 'A')
        {
            printf("%d ",a[0]);
        }
        if(s[i] == 'B')
        {
            printf("%d ",a[1]);
        }
        if(s[i] == 'C')
        {
            printf("%d ",a[2]);
        }
    }
    return 0;
}
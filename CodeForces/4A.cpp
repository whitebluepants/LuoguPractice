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
int iseven[101];
int even[101];
int main()
{
    int w = read();

    for(int i = 1;i <= 50;i ++)
    {
        iseven[i * 2] = true;
        even[i] = i * 2;
    }

    for(int i = 1;i <= 50;i ++)
    {
        int a = even[i];
        int b = w - a;
        if(iseven[b] == true)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");

    return 0;
}
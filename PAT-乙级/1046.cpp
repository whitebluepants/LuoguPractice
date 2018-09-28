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
int main()
{
    int n = read();
    int cnt1 = 0,cnt2 = 0;

    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read(),c = read(),d = read();
        int temp = a + c;
        if(b == temp && d == temp)
        {
            continue;
        }
        else if(b == temp)
        {
            cnt2 ++;
        }
        else if(d == temp)
        {
            cnt1 ++;
        }
    }
    printf("%d %d",cnt1,cnt2);

    return 0;
}
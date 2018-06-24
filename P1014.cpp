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

    int a = 1,b = 1,flag = 1;
    for(int i = 1;i < n;i ++)
    {
        if(flag == 1)
        {
            b ++;
            flag = 2;
        }
        else if(flag == 2)
        {
            a ++,b --;
            if(b == 1)
            {
                flag = 3;
            }
        }
        else if(flag == 3)
        {
            a ++;
            flag = 4;
        }
        else if(flag == 4)
        {
            a --,b ++;
            if(a == 1)
            {
                flag = 1;
            }
        }
    }
    printf("%d/%d",a,b);

    return 0;
}
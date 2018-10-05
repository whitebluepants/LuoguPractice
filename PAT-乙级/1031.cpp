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
    int a[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char m[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
    char s[19] = {};

    int n = read(),flag = 0;

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s);
        int sum = 0;

        for(int j = 0;j < 17;j ++)
        {
            sum += (s[j] - '0') * a[j];
        }
        sum %= 11;
        if(m[sum] != s[17])
        {
            printf("%s\n",s);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("All passed");
    }
    return 0;
}
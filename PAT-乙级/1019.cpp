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
bool cmp1(int a,int b)
{
    return a > b;
}
bool cmp2(int a,int b)
{
    return a < b;
}
int main()
{
    int a[4] = {};
    int flag = 0;
    for(int i = 0;i < 4;i ++)
    {
        scanf("%1d",&a[i]);
        if(i != 0)
        {
            if(a[i] != a[i - 1])
            {
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        printf("%d%d%d%d - %d%d%d%d = 0000",a[0],a[1],a[2],a[3],a[0],a[1],a[2],a[3]);
        return 0;
    }

    int t = 0;
    while(t != 6174)
    {
        int aa = 0,b = 0;
        sort(a,a + 4,cmp1);

        for(int i = 0;i < 4;i ++)
        {
            aa = aa * 10 + a[i];
        }
        sort(a,a + 4,cmp2);
        for(int i = 0;i < 4;i ++)
        {
            b = b * 10 + a[i];
        }
        t = aa - b;
        printf("%04d - %04d = %04d\n",aa,b,t);
        int temp = t;
        // 一开始条件是写成temp>0 注意如果输入1000 会出现1000-0001=0999
        // 如果用temp>0 那么只能给数组后3位数赋予999 第一位原应该为0的 还是1没有被改变
        for(int i = 0;i < 4;i ++) 
        {
            a[i] = temp % 10;
            temp /= 10;
        }
    }
    
    return 0;
}
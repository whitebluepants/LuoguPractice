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
long long ans[1000000];
int main()
{
    int n = read(),begin = 1,end = n / 2 + 1;
    
    ans[1] = 1;
    for(int i = 2;i <= n / 2 + 1;i ++)
    {
        ans[i] = i + ans[i - 1];
        if(ans[i] - ans[i - 2] > n)
        {
            end = i;
            break;
        }
    }

    for(int i = 1;i <= end;i ++)
    {
        int right = i;
        long long left = ans[i] - n;
        if(left < 0)
        {
            continue;
        }
        int l = 1,r = i,flag = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(ans[mid] == left)
            {
                flag = 1;
                left = mid + 1;
                break;
            }
            else if(ans[mid] > left)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if(flag == 1)
        {
            printf("%lld %d\n",left,right);
        }
    }

    return 0;
}
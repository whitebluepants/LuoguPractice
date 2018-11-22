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
int ans[101];
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i] = read();
    }

    int max = 0;
    int l = 0,left = 0,right = 0;
    int flag = 0,sum = 0;

    for(int i = 0;i < n;i ++)
    {
        if(ans[i] == 0 && flag == 0)
        {
            flag = 1;
            l = i;
        }
        if(ans[i] == 0)
        {
            sum += 1;
        }
        else
        {
            sum -= 1;
        }

        if(sum > max)
        {
            max = sum;
            left = l;
            right = i;
        }

        if(sum < 0)
        {
            flag = 0;
            sum = 0;
        }
    }
	
    int count = 0;
    for(int i = 0;i < n;i ++)
    {
        if(i >= left && i <= right)
        {
            if(ans[i] == 0)
            {
                count ++;
            }
        }
        else if(ans[i] == 1)
        {
            count ++;
        }
    }
	
	printf("%d",count);
	
    return 0;
}


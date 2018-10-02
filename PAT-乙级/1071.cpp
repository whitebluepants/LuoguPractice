#include <stdio.h>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
int main()
{
    int n = read(),k = read();

    for(int i = 0;i < k;i ++)
    {
        int a = read(),t = read(),count = read(),b = read();
        if(count > n)
        {
            printf("Not enough tokens.  Total = %d.\n",n);
            continue;
        }
        int flag = 0;
        if(a > b)
        {
            if(t == 0)
            {
                n += count;
            }
            else
            {
                flag = 1;
                n -= count;
            }
        }
        else
        {
            if(t == 0)
            {
                flag = 1;
                n -= count;
            }
            else
            {
                n += count;
            }
        }
        if(n < 0)
        {  
            n = 0;
        }
        if(flag)
        {
            printf("Lose %d.  Total = %d.\n",count,n);
        }
        else
        {
            printf("Win %d!  Total = %d.\n",count,n);
        }
        
        if(n == 0)
        {
            printf("Game Over.\n");
            break;
        }
    }

    return 0;
}
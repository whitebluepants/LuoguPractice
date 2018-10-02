#include <stdio.h>
#include <math.h>
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
struct node
{
    int check;
    int flag;
};
node ans[10001];
int isprime(int x)
{
    if(x == 1)
    {
        return 0;
    }
    if(x == 2)
    {
        return 1;
    }
    for(int i = 2;i <= sqrt(x);i ++)
    {
        if(x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n = read();
    
    for(int i = 1;i <= n;i ++)
    {
        int t = read();
        ans[t].check = 1;
        if(i == 1)
        {
            ans[t].flag = 1;
        }
        else if(isprime(i))
        {
            ans[t].flag = 2;
        }
        else
        {
            ans[t].flag = 3;
        }
    }

    int m = read();
    for(int i = 0;i < m;i ++)
    {
        int t = read();
        printf("%04d: ",t);
        if(!ans[t].check)
        {
            printf("Are you kidding?\n");
        }
        else if(ans[t].check == 2)
        {
            printf("Checked\n");
        }
        else
        {
            ans[t].check = 2;
            switch(ans[t].flag)
            {
                case 1: printf("Mystery Award\n"); break;
                case 2: printf("Minion\n"); break;
                case 3: printf("Chocolate\n");
            }
        }
    }

    return 0;
}
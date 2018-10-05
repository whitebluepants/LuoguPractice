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
int a[10];
int main()
{
    int n = read();
    for(int i = 0;i < n;i ++)
    {
        int t;
        scanf("%1d",&t);
        a[t] ++;
    }
    
    if(a[8] == 0 || n < 11)
    {
        printf("0");
        return 0;
    }
    
    int max = n / 11;

    if(a[8] >= max)
    {
        printf("%d",max);
    }
    else
    {
        printf("%d",a[8]);
    }

    return 0;
}
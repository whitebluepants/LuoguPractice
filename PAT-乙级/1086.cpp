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
    int a = read(),b = read();

    int c = a * b;

    if(c == 0)
    {
        printf("0");
    }
    else
    {
        int flag = 0;
        while(c > 0)
        {
            int temp = c % 10;
            c /= 10;
            if(flag == 0 && temp != 0)
            {
                flag = 1;
            }
            if(flag)
            {
                printf("%d",temp); 
            }
        }
    }
    return 0;
}
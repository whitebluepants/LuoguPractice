#include <stdio.h>
#include <string.h>
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
    int n = read():

    for(int i = 0;i < n;i ++)
    {
        char s[4] = {};
        for(int j = 0;j < 4;j ++)
        {
            scanf("%s",s);
            if(s[2] == 'T')
            {
                printf("%d",s[0] - 'A' + 1);
            }
        }
    }
    return 0;
}
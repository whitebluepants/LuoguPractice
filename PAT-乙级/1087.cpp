#include <stdio.h>
#include <map>
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
map<int,int> m;
int main()
{
    int n = read();
    int count = 0;

    for(int i = 1;i <= n;i ++)
    {
        int temp = (i / 2) + (i / 3) + (i / 5);
        if(m[temp] == 0)
        {
            m[temp] ++;
            count ++;
        }
    }

    printf("%d",count);

    return 0;
}
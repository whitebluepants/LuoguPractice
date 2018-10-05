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
int heap[1005];
void Insert(int item,int index)
{
    int i = index;

    for(;heap[i / 2] > item;i /= 2)
    {
        heap[i] = heap[i / 2];
    }
    heap[i] = item;
}
int main()
{
    int n = read(),m = read();

    heap[0] = -999999999;
    for(int i = 1;i <= n;i ++)
    {
        int t = read();
        Insert(t,i);
    }

    for(int i = 0;i < m;i ++)
    {
        int t = read();
        int flag = 0;
        for(int j = t;j > 0;j /= 2)
        {
            if(flag)
            {
                printf(" ");
            }
            printf("%d",heap[j]);
            flag = 1;
        }
        printf("\n");
    }

    return 0;
}
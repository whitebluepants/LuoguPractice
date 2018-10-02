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
int ans[10000];
int main()
{
    int n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        int t = read();
        ans[t] = 1;
    }
    
    int count1 = 0,count2 = 0;
    char s[5] = {};
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s);
        int count = read();
        int flag = 0;
        for(int j = 0;j < count;j ++)
        {
            int t = read();
            if(ans[t])
            {
                if(flag == 0)
                {
                    count1 ++;
                    printf("%s: %04d",s,t);
                    flag = 1;
                }
                else
                {
                    printf(" %04d",t);
                }
                count2 ++;
            }
        }
        if(flag)
        {
            printf("\n");
        }
    }
    printf("%d %d",count1,count2);

    return 0;
}
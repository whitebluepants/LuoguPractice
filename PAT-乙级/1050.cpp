#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') {if(ch == '-')f = 0; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
	return f?x:x*-1;
}
bool cmp(int a,int b)
{
    return a > b;
}
int num[10001];
int ans[10001][1001];
int main()
{
    int N = read();
    int n,m,minn = 9999;

    for(int i = 0;i < N;i ++)
    {
        scanf("%d",&num[i]); // 用快速输入超时 谜
    }
    for(int i = 1;i <= sqrt(N);i ++)
    {
        if(N % i == 0)
        {
            if(N / i - i < minn)
            {
                minn = N / i - i;
                n = i;
            }
        }
    }
    m = N / n;

    sort(num,num + N,cmp);

    int t = 0;
    int i = 0,j = 0;
    ans[i][j] = num[t ++];

    while(t < N)
    {
        while(j + 1 < n && !ans[i][j + 1])
        {
            ans[i][++ j] = num[t ++];
        }    
        while(i + 1 < m && !ans[i + 1][j])
        {
            ans[++ i][j] = num[t ++];
        }
        while(j - 1 >= 0 && !ans[i][j -1])
        {
            ans[i][-- j] = num[t ++];
        }
        while(i - 1 >= 0 && !ans[i - 1][j])
        {
            ans[-- i][j] = num[t ++];
        }
    }
    
    for(int i = 0;i < m;i ++)
    {
        printf("%d",ans[i][0]);
        for(int j = 1;j < n;j ++)
        {
            printf(" %d",ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
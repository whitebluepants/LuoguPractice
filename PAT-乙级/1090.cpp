#include <stdio.h>
#include <vector>
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
map<int,vector<int>> mm;
int main()
{
    int n = read(),m = read();

    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read();
        mm[a].push_back(b);
        mm[b].push_back(a);
    }

    for(int i = 0;i < m;i ++)
    {
        int k = read();
        int ans[1001] = {};
        int v[100005] = {};
        int flag = 0;

        for(int j = 0;j < k;j ++)
        {
            ans[j] = read();
            v[ans[j]] = 1;
        }
        for(int j = 0;j < k;j ++)
        {
            int t = ans[j];
            for(int l = 0;l < mm[t].size();l ++)
            {
                if(v[mm[t][l]])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }

    return 0;
}
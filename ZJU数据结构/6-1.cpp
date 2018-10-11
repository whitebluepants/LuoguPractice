#include <stdio.h>
#include <string.h>
#include <queue>
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
int visited[10];
int flag[10];
int k,v,e;
int map[10][10];
void dfs(int t)
{
	if(visited[t])
	{
		return;
	}
	visited[t] = 1;
	flag[k ++] = t;
	
	for(int i = 0;i < v;i ++)
	{
	    if(visited[i] == 0 && map[t][i] == 1)
	    {
	        dfs(i);
	    }
	}
}
int main()
{
    v = read(),e = read();
    
    for(int i = 0;i < e;i ++)
    {
        int a = read(),b = read();
        map[a][b] = 1;
        map[b][a] = 1;
    }

	for(int i = 0;i < v;i ++)
	{
		memset(flag,0,sizeof(flag));
		k = 0;
		if(!visited[i])
		{
			dfs(i);
            printf("{ ");
            int f = 0;
            for(int j = 0;j < k;j ++)
            {
                if(f)
                {
                    printf(" ");
                }
                printf("%d",flag[j]);
                f = 1;
            }
            printf(" }\n");
		}
	}	

    memset(visited,0,sizeof(visited));

    for(int i = 0;i < v;i ++)
    {
        memset(flag,0,sizeof(flag));
		k = 0;
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            printf("{");
            while(q.size())
            {
                int t = q.front();
                q.pop();
                printf(" %d",t);

                for(int j = 0;j < v;j ++)
                {
                    if(visited[j] == 0 && map[t][j])
                    {
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
            printf(" }\n");
        }
    }

	return 0;
}
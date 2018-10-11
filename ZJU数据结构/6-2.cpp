#include <stdio.h>
#include <math.h>
#include <queue>
#include <utility>
#include <stdlib.h>
using namespace std;
typedef pair<int,int> pp;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
int visited[101];
int ans[101][2];
int main()
{
    int n = read(),d = read();

    for(int i = 0;i < n;i ++)
    {
        ans[i][0] = read(),ans[i][1] = read();
    }
    
    queue<pp> q;
    q.push(pp(0,0));

    while(q.size())
    {
        pp t = q.front();
        q.pop();
        int x1 = t.first,y1 = t.second;

        int x = abs(x1),y = abs(y1);
        if(x + d >= 50 || y + d >= 50)
        {
            printf("Yes");
            return 0;
        }

        for(int i = 0;i < n;i ++)
        {
            if(!visited[i])
            {
                int x2 = ans[i][0],y2 = ans[i][1];
                double dis = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
                double temp = d;
                if(x1 == 0 && y1 == 0)
                {
                    temp += 7.5;
                }
                if(temp >= dis)
                {
                    visited[i] = 1;
                    q.push(pp(x2,y2));
                }
            }
        }
    }
    printf("No");

    return 0;
}
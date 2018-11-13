#include <stdio.h>
#include <algorithm>
using namespace std;
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
struct node
{
    int name;
    int grade;
    int flag; // 是否显示
    int g[6];
    int perfect[6];
    int perfectCount;

    node()
    {
        for(int i = 1;i <= 5;i ++)
        {
            g[i] = -1;
        }
    }
};
bool cmp(node a,node b)
{   
    if(a.flag == b.flag)
    {
        if(a.grade == b.grade)
        {
            if(a.perfectCount == b.perfectCount)
            {
                return a.name < b.name;
            }
            return a.perfectCount > b.perfectCount;
        }
        return a.grade > b.grade;
    }
    return a.flag > b.flag;
}
node *ans = new node[100010];
int problem[6];
int main()
{
    int n = read(),m = read(),k = read();

    for(int i = 1;i <= m;i ++)
    {
        problem[i] = read();
    }

    for(int i = 0;i < k;i ++)
    {
        int a = read(),b = read(),c = read();
        
        ans[a].name = a;
        if(ans[a].g[b] == -1 && c == -1)
        {
            ans[a].g[b] = 0;
            continue;
        }
        ans[a].flag = 1;
        if(c > ans[a].g[b])
        {
            if(ans[a].g[b] != -1)
            {
                ans[a].grade -= ans[a].g[b];
                ans[a].grade += c;
            }
            else
            {
                ans[a].grade += c;
            }
            ans[a].g[b] = c;
        }
        if(c == problem[b] && ans[a].perfect[b] == 0)
        {
            ans[a].perfect[b] = 1;
            ans[a].perfectCount ++;
        }
    }
    
    sort(ans + 1,ans + 1 + 99999,cmp);

    int rank = 1;
    int temp = 1;
    for(int i = 1;i <= n;i ++)
    {
        if(ans[i].flag == 0)
        {
            continue;
        }
        printf("%d %05d %d",rank,ans[i].name,ans[i].grade);
        for(int j = 1;j <= m;j ++)
        {
            printf(" ");
            if(ans[i].g[j] == -1)
            {
                printf("-");
            }
            else
            {
                printf("%d",ans[i].g[j]);
            }
        }
        printf("\n");
        if(ans[i].grade == ans[i + 1].grade)
        {
            temp ++;
        }
        else
        {
            rank += temp;
            temp = 1;
        }
    }

    return 0;
}
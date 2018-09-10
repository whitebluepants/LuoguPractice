#include <stdio.h>
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
    int father;
    int relation;
};
node ans[50001];
int find(int x)
{
    if(x == ans[x].father)
    {
        return x;
    }
    else
    {
        // 简单例子 rootx->x->xx->xxx 那么要计算rootx->x + x->xx + xx->xxx = rootx->xxx
        // 错误写法 应该先递归找出根节点再计算 如果先计算 就会得到一个x->xx + xx->xxx
        //ans[x].relation = (ans[ans[x].father].relation + ans[x].relation) % 3;
        //ans[x].father = find(ans[x].father);
    
        int temp = ans[x].father; //路径压缩
        ans[x].father = find(temp);
        ans[x].relation = (ans[x].relation + ans[temp].relation) % 3; //关系域更新
        
        return ans[x].father;

    }
}
int main()
{
    int n = read(),m = read();
    int count = 0;

    for(int i = 1;i <= n;i ++)
    {
        ans[i].father = i;
        ans[i].relation = 0; // 0 - 同类 1 - i吃根节点 2 - i被根节点吃
    }

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        if(b <= 0 || b > n || c <= 0 || c > n)
        {
            count ++;
            continue;
        }
        if(a == 2 && b == c)
        {
            count ++;
            continue;
        }

        int rootx = find(b), rooty = find(c);
        if(rootx != rooty)
        {
            ans[rooty].father = rootx;
            ans[rooty].relation = (ans[b].relation + a - 1 + 3 - ans[c].relation) % 3;
        }
        else
        {
            if(a == 1 && ans[b].relation != ans[c].relation)
            {
                count ++;
            }
            else if(a == 2 && (3 - ans[b].relation + ans[c].relation) % 3 != 1)
            {
                count ++;
            }
        }
    }

    printf("%d",count);

    return 0;
}
#include <stdio.h>
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
int node[100]; // 用来判断哪些点出现在树上 是用来配合找出哪个点是树根
int nn[100];   // 保存非叶子点 也就是除第一行以外 每一行的第一个数
int ans[100][100];  // 用来保存每个结点的子节点
int main()
{
    int n = read(),m = read();

    if(n == 0)
    {
        // 为0的时候 不处理直接结束 处理会段错误
        return 0;
    }

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read();
        node[a] = 1;    // a这个结点出现过 标记
        nn[i] = a;      // a不是叶子 保存
        ans[a][0] = b;  // 每个树节点的数组 0下标保存他有多少个孩子 直接保存为b
        for(int j = 1;j <= b;j ++)
        {
            int c = read(); // 读入a的子节点
            ans[a][j] = c;  // 保存到a数组上
            node[c] = 2;    // 标记为2是用来找出根结点. 因为树的根入度为0 某个点如果他在这里出现在这里说明有入度
        }
    }
    int root = 1;
    for(int i = 0;i < m;i ++)
    {
        if(node[nn[i]] == 1) // 如果是在nn数组里(也就是 是非叶子结点) 并且标记是1 不是2 代表是树根
        {
            root = nn[i];
            break;
        }
    }

    queue<int> q1;  //  用来保存每轮操作的结点
    queue<int> q2;  //  用来缓存用 当temp
    q1.push(root);  //  第一轮先把根丢进队列1
    int flag = 0;

    // 题意是要找每层的叶子结点
    // 以下操作原理接近bfs 或者就是bfs
    while(1)
    {
        int count = 0;  //  每层的叶子结点树
        while(q1.size())
        {
            int temp = q1.front();  //  把队列1的点全部弄出来
            q1.pop();
        
            if(ans[temp][0] == 0)   //  如果该结点的出度为0 说明是叶子
            {
                count ++;
            }

            for(int i = 1;i <= ans[temp][0];i ++)   //  找出队列弹出来的结点 的 子节点 并丢到队列2保存
            {
                int t = ans[temp][i];
                q2.push(t);
            }
        }
        if(flag)
        {
            printf(" ");
        }
        printf("%d",count);
        flag = 1;
        
        if(q2.size() == 0)  //  如果队列2为0 说明已经结束了
        {
            break;
        }
        
        while(q2.size())    //  把结点全部丢回队列1做下一轮操作
        {
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
    }

    return 0;
}
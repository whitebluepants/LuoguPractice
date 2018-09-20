#include <stdio.h>
#include <stdlib.h>
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
struct node
{
	char t;
	int left, right;
};
node a[10], b[10];
int createTree(node a[])
{
	int n = read(), root = 0;
	int visited[10] = {};
	char q, w;
	for (int i = 0; i < n; i++)
	{
		scanf(" %c %c %c", &a[i].t, &q, &w);
		if (q != '-')
		{
			a[i].left = q - '0';
			visited[q - '0'] = 1;
		}
		else
		{
			a[i].left = -1;
		}

		if (w != '-')
		{
			a[i].right = w - '0';
			visited[w - '0'] = 1;
		}
		else
		{
			a[i].right = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			root = i;
			break;
		}
	}
	return n == 0?-1:root;
}
/*
    如果现在都是指向空结点 返回1
    
    如果a树指向空 b树指向非空 或者反过来 说明两树不一样 返回0
    
    如果指向的结点内容不一样 返回0
    
    如果两树的左结点都是空的 那就检查他们的右结点
    
    如果两树的左结点都不为空 并且他们的左结点的内容是一样的 检查两树的左结点和右结点
    是否一样 必须左右都是一样的 如其中有不一样的 返回0 反之1
    
    如果两树的左结点有空的 或者他们的左结点内容不一样 交叉检查他们的左右结点(考虑子结点互换)
*/
int check(int t1,int t2)
{
    if(t1 == -1 && t2 == -1)
    {
        return 1;
    }
    if(t1 == -1 && t2 != -1 || t1 != -1 && t2 == -1)
    {
        return 0;
    }
    if(a[t1].t != b[t2].t)
    {
        return 0;
    }
    if(a[t1].left == -1 && b[t2].left == -1)
    {
        return check(a[t1].right,b[t2].right);
    }
    if(a[t1].left != -1 && b[t2].left != -1 && a[a[t1].left].t == b[b[t2].left].t)
    {
        return (check(a[t1].left,b[t2].left) && check(a[t1].right,b[t2].right));
    }
    else
    {
        return (check(a[t1].left,b[t2].right) && check(a[t1].right,b[t2].left));
    }
}
int main()
{
	int tree1 = createTree(a);
	int tree2 = createTree(b);
    
    if(tree1 == -1 && tree2 == -1)
    {
        printf("Yes\n");
        return 0;
    }
    
	int flag = check(tree1,tree2);

	if(flag)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}

	return 0;
}
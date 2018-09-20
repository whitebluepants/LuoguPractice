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
struct tree
{
	int data;
	int left,right;
};
tree ans[10];
int createTree(tree a[])
{
	int n = read();
	int root = -1;
	int visited[10] = {};

	if(n)
	{
		char a,b;
		for(int i = 0;i < n;i ++)
		{
			scanf(" %c %c",&a,&b);
			ans[i].data = i;
			if(a != '-')
			{
				ans[i].left = a - '0';
				visited[a - '0'] = 1;
			}
			else
			{
				ans[i].left = -1;
			}
			if(b != '-')
			{
				ans[i].right = b - '0';
				visited[b - '0'] = 1;
			}
			else
			{
				ans[i].right = -1;
			}
		}	

		for(int i = 0;i < n;i ++)
		{
			if(visited[i] == 0)
			{
				root = i;
				break;
			}
		}
	}

	return root;
}
void seq(int t)
{
	int flag = 0;
	queue<int> q;
	q.push(t);

	while(q.size())
	{
		int temp = q.front();
		q.pop();

		if(ans[temp].left == -1 && ans[temp].right == -1)
		{
			if(flag)
			{
				printf(" ");
			}
			printf("%d",temp);
			flag = 1;
			continue;
		}

		if(ans[temp].left != -1)
		{
			q.push(ans[temp].left);
		}
		if(ans[temp].right != -1)
		{
			q.push(ans[temp].right);
		}
	}
}
int main()
{
	int roota = createTree(ans);

	seq(roota);

	return 0;
}
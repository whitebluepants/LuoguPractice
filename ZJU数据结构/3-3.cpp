#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
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
typedef struct node* List;
struct node
{
	int data;
	List left;
	List right;
};
struct oper
{
	string op;
	int n;
};
int stack[61];
oper ans[61];
int pre[31];
int in[31];
List createTree(int preb,int pree,int inb,int ine)
{
    if(pree < preb || ine < inb)
    {
        return NULL;
    }
	List L = new node();
	List P = L;

	P->data = pre[preb];
	P->left = NULL;
	P->right = NULL;

	int len1;
	int inroot;
	for(int i = inb;i <= ine;i ++)
	{
		if(in[i] == pre[preb])
		{
			len1 = i - inb;
			inroot = i;
			break;
		}
	}
	
	if(len1 > 0)
	{
		P->left = createTree(preb + 1,preb + len1,inb,inroot - 1);
	}
	if(ine - inb > 0)
	{
		P->right = createTree(preb + 1 + len1,pree,inroot + 1,ine);
	}
	
	return L;
}
int flag = 0;
void preorder(List L)
{
	if(L)
	{
		preorder(L->left);
		preorder(L->right);
		if(flag)
		{
		    printf(" ");
		}
		printf("%d",L->data);
		flag = 1;
	}
}
int main()
{
	int n = read();
    
	for(int i = 0;i < 2 * n;i ++)
	{
		cin >> ans[i].op;
		if(ans[i].op == "Push")
		{
			cin >> ans[i].n;
		}
	}

	int t = ans[0].n;
	int i = 1,j = 1,a = 0,b = 0;
	pre[a ++] = t;
	stack[i] = t;

	while(i || j < n * 2)
	{
		if(ans[j].op == "Push")
		{
			pre[a ++] = ans[j].n;
			stack[++ i] = ans[j ++].n;
		}
		else
		{
			int temp = stack[i --];
			in[b ++] = temp;
			j ++;
		}
	}

	List tree = createTree(0,n - 1,0,n - 1);
    
    preorder(tree);
    
    return 0;
}
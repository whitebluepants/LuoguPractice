#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
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
	int weight;
	char ch;
	tree* left;
	tree* right;
};
struct Jnode
{
	int flag;
	Jnode* left;
	Jnode* right;
};
typedef Jnode* List2;
typedef tree* List;
tree heap[64];
int heapsize;
int chCount[64];
List deleteMin()
{
	List T = (List)malloc(sizeof(tree));
	*T = heap[1];

	tree temp = heap[heapsize--];
	int parent, child;
	for (parent = 1; parent * 2 <= heapsize; parent = child)
	{
		child = parent * 2;
		if (child + 1 <= heapsize && heap[child + 1].weight < heap[child].weight)
		{
			child++;
		}
		if (heap[child].weight > temp.weight)
		{
			break;
		}
		else
		{
			heap[parent] = heap[child];
		}
	}
	heap[parent] = temp;

	return T;
}
void Insert(List T)
{
	int i = ++heapsize;

	for (; heap[i / 2].weight > T->weight; i /= 2)
	{
		heap[i] = heap[i / 2];
	}
	heap[i] = *T;
}
void createHeap(int n)
{
	char ch;
	int count;
	heap[0].weight = -9999999;
	for (int i = 1; i <= n; i++)
	{
		scanf(" %c %d", &ch, &count);
		List T = (List)malloc(sizeof(tree));
		T->ch = ch;
		T->weight = count;
		T->left = NULL;
		T->right = NULL;
		chCount[i] = count;
		Insert(T);
	}
}
List CreateHafumanTree()
{
	List T;
	int t = heapsize;
	for (int i = 1; i < t; i++) // 注意不能直接用heapsize作为循环条件 因为heapsize在deleteMin的时候会改变
	{
		T = (List)malloc(sizeof(tree));
		T->left = deleteMin();
		T->right = deleteMin();
		T->weight = T->left->weight + T->right->weight;
		T->ch = '@';
		Insert(T);
	}
	T = deleteMin();

	return T;
}
int calWpl(List T, int deep)
{
	if (!T->left && !T->right)
	{
		return deep * T->weight;
	}
	else
	{
		return calWpl(T->left, deep + 1) + calWpl(T->right, deep + 1);
	}
}
bool Judge(string s, List2 J)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			if (J->left == NULL)
			{
				List2 temp = (List2)malloc(sizeof(Jnode));
				temp->left = NULL;
				temp->right = NULL;
				J->left = temp;
			}
			else
			{
				if (J->left->flag == 1)
				{
					return false;
				}
			}
			J = J->left;
		}
		else
		{
			if (J->right == NULL)
			{
				List2 temp = (List2)malloc(sizeof(Jnode));
				temp->left = NULL;
				temp->right = NULL;
				J->right = temp;
			}
			else
			{
				if (J->right->flag == 1)
				{
					return false;
				}
			}
			J = J->right;
		}
	}
	J->flag = 1;
	if (J->left == NULL && J->right == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n = read();

	createHeap(n);

	List HT = CreateHafumanTree();

	int wpl = calWpl(HT, 0);

	int m = read();

	for (int i = 0; i < m; i++)
	{
		bool result;
		int len = 0, flag = 0;
		char ch;
		List2 J = (List2)malloc(sizeof(Jnode));
		J->left = NULL;
		J->right = NULL;
		string s;

		for (int j = 1; j <= n; j++)
		{
			cin >> ch >> s;
			len += chCount[j] * s.size();

			if (flag == 0)
			{
				result = Judge(s, J);
				if (!result)
				{
					flag = 1;
				}
			}
		}
		if (result && (len == wpl))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}
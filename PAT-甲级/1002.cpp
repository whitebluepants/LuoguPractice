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
	int e;
	double c;
	node* next;
};
typedef node* List;
int count;
List add(List L1, List L2)
{
	L1 = L1->next;
	L2 = L2->next;
	List L = (List)malloc(sizeof(node));
	List P = L;

	while (L1 && L2)
	{
		List temp = (List)malloc(sizeof(node));
		if (L1->e == L2->e)
		{
			if (L1->c + L2->c == 0)
			{
				;
			}
			else
			{
				count++;
				temp->e = L1->e;
				temp->c = L1->c + L2->c;
				P->next = temp;
				P = P->next;
			}
			L1 = L1->next;
			L2 = L2->next;
		}
		else if (L1->e > L2->e)
		{
			count++;
			temp->e = L1->e;
			temp->c = L1->c;
			L1 = L1->next;
			P->next = temp;
			P = P->next;
		}
		else
		{
			count++;
			temp->e = L2->e;
			temp->c = L2->c;
			L2 = L2->next;
			P->next = temp;
			P = P->next;
		}
	}
	while (L1)
	{
		count++;
		List temp = (List)malloc(sizeof(node));
		temp->e = L1->e;
		temp->c = L1->c;
		L1 = L1->next;
		P->next = temp;
		P = P->next;
	}
	while (L2)
	{
		count++;
		List temp = (List)malloc(sizeof(node));
		temp->e = L2->e;
		temp->c = L2->c;
		L2 = L2->next;
		P->next = temp;
		P = P->next;
	}
	P->next = NULL;
	return L;
}
int main()
{
	List L1 = (List)malloc(sizeof(node));
	List L2 = (List)malloc(sizeof(node));
	int k1, k2;

	List P = L1;
	k1 = read();
	for (int i = 0; i < k1; i++)
	{
		List temp = (List)malloc(sizeof(node));
		scanf("%d %lf", &temp->e, &temp->c);
		temp->next = NULL;
		P->next = temp;
		P = P->next;
	}
	P->next = NULL;
	k2 = read();
	P = L2;
	for (int i = 0; i < k2; i++)
	{
		List temp = (List)malloc(sizeof(node));
		scanf("%d %lf", &temp->e, &temp->c);
		temp->next = NULL;
		P->next = temp;
		P = P->next;
	}
	List L = add(L1, L2);
	printf("%d", count);

	L = L->next;
	while (L)
	{
		printf(" %d %.1f", L->e, L->c);
		L = L->next;
	}

	return 0;
}
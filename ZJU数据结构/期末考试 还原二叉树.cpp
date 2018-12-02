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
    char data;
    node *left;
    node *right;
};
typedef node* List;
char pre[51];
char in[51];
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
int Max = 0;
void findHeight(List L,int h)
{
    if(L->left == NULL && L->right == NULL)
    {
        if(h > Max)
        {
            Max = h;
        }
        return ;
    }
    if(L->right)
    {
    	findHeight(L->right,h + 1);
    }
    if(L->left)
    {
    	findHeight(L->left,h + 1);
    }
}
int main()
{
	// freopen("in.txt","r",stdin);
    int n = read();

    scanf("%s %s",pre,in);
    List tree = createTree(0,n - 1,0,n - 1);
    findHeight(tree,1);
    printf("%d",Max);

    return 0;
}
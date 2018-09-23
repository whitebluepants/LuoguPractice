#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
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
    int data;
    int height;
    node* left;
    node* right;
};
typedef node* List;
int get_height(List tree)
{
    return tree == NULL?0:tree->height;
}
List ll_rotation(List k2)
{
    List k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(get_height(k2->left),get_height(k2->right)) + 1;
    k1->height = max(get_height(k1->left),get_height(k1->right)) + 1;

    return k1;
}
List rr_rotation(List k2)
{
    List k1;
    k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    k1->height = max(get_height(k1->left),get_height(k1->right)) + 1;
    k2->height = max(get_height(k2->left),get_height(k2->right)) + 1;

    return k1;
}
List lr_rotation(List k3)
{
    k3->left = rr_rotation(k3->left);
    
    return ll_rotation(k3);
}
List rl_rotation(List k3)
{
    k3->right = ll_rotation(k3->right);

    return rr_rotation(k3);
}
List avl_insert(List L,int data)
{
    if(!L)
    {
        L = (List)malloc(sizeof(node));
        L->data = data;
        L->height = 0;
        L->left = NULL;
        L->right = NULL;
    }
    else if(data < L->data)
    {
        L->left = avl_insert(L->left,data);
        if(get_height(L->left) - get_height(L->right) == 2)
        {
            if(data < L->left->data)
            {
                L = ll_rotation(L);
            }
            else
            {
                L = lr_rotation(L);
            }
        }
    }
    else if(data > L->data)
    {
        L->right = avl_insert(L->right,data);

        if(get_height(L->right) - get_height(L->left) == 2)
        {
            if(data > L->right->data)
            {
                L = rr_rotation(L);
            }
            else
            {
                L = rl_rotation(L);
            }
        }
    }
    L->height = max(get_height(L->left),get_height(L->right)) + 1;

    return L;
}
List createTree()
{
    int n = read();
    List L = NULL;

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        L = avl_insert(L,t);
    }
    return L;
}
int main()
{
    List L = createTree();

    printf("%d",L->data);

    return 0;
}
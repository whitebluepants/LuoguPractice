#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
void PreorderTraversal(BinTree L)
{
    if(L)
    {
        printf(" %d",L->Data);
        PreorderTraversal(L->Left);
        PreorderTraversal(L->Right);
    }
}
void InorderTraversal(BinTree L)
{
    if(L)
    {
        InorderTraversal(L->Left);
        printf(" %d",L->Data);
        InorderTraversal(L->Right);
    }
}
BinTree Insert(BinTree L,ElementType data)
{
    if(!L)
    {
        L = (BinTree)malloc(sizeof(struct TNode));
        L->Data = data;
        L->Left = NULL;
        L->Right = NULL;
    }
    else if(L->Data > data)
    {
        L->Left = Insert(L->Left,data);
    }
    else if(L->Data < data)
    {
        L->Right = Insert(L->Right,data);
    }
    return L;
}
Position Find(BinTree L,ElementType data)
{
    if(!L)
    {
        return NULL;
    }
    else if(L->Data > data)
    {
        Find(L->Left,data);
    }
    else if(L->Data < data)
    {
        Find(L->Right,data);
    }
    else
    {
        return L;
    }
}
Position FindMax(BinTree L)
{
    if(!L || !L->Right)
    {
        return L;
    }
    else
    {
        FindMax(L->Right);
    }
}
Position FindMin(BinTree L)
{
    if(!L || !L->Left)
    {
        return L;
    }
    else
    {
        FindMin(L->Left);
    }
}
BinTree Delete(BinTree L,ElementType data)
{
    if(!L)
    {
        printf("Not Found\n");
    }
    else if(L->Data > data)
    {
        L->Left = Delete(L->Left,data);
    }
    else if(L->Data < data)
    {
        L->Right = Delete(L->Right,data);
    }
    else
    {
        if(L->Right && L->Left)
        {
            BinTree tmp = FindMin(L->Right);
            L->Data = tmp->Data;
            L->Right = Delete(L->Right,L->Data);
        }
        else
        {
            BinTree temp = L;
            if(L->Left)
            {
                L = L->Left;
                free(temp);
            }
            else if(L->Right)
            {
                L = L->Right;
                free(temp);
            }
            else
            {
                L = NULL;
            }
        }
    }
    return L;
}
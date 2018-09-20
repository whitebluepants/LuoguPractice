#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
List Read()
{
    List L = (List)malloc(sizeof(struct Node));
    int n;
    scanf("%d",&n);
    
    List P = L;
    
    for(int i = 0;i < n;i ++)
    {
        List p = (List)malloc(sizeof(struct Node));
        scanf("%d",&p->Data);
        P->Next = p;
        P = P->Next;
    }
    P->Next = NULL;

    return L;
}
void Print(List L)
{
    if(L->Next == NULL)
    {
        printf("NULL\n");
        return;
    }
    L = L->Next;
    while(L)
    {
        printf("%d ",L->Data);
        L = L->Next;
    }
    printf("\n");
}
List Merge(List L1, List L2)
{
    List L = (List)malloc(sizeof(struct Node));
    List p = L;

    List LL1 = L1->Next;
    List LL2 = L2->Next;

    while(LL1 && LL2)
    {
        List t = (List)malloc(sizeof(struct Node));
        if(LL1->Data > LL2->Data)
        {
            t->Data = LL2->Data;
            LL2 = LL2->Next;
        }
        else
        {
            t->Data = LL1->Data;
            LL1 = LL1->Next;
        }
        p->Next = t;
        p = p->Next;
    }

    while(LL1)
    {
        List t = (List)malloc(sizeof(struct Node));
        t->Data = LL1->Data;
        LL1 = LL1->Next;
        p->Next = t;
        p = p->Next;
    }

    while(LL2)
    {
        List t = (List)malloc(sizeof(struct Node));
        t->Data = LL2->Data;
        LL2 = LL2->Next;
        p->Next = t;
        p = p->Next;
    }
    p->Next = NULL;
    L1->Next = NULL;
    L2->Next = NULL;
    
    return L;
}
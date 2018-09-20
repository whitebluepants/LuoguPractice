#include <stdio.h>
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
struct Node
{
    int c;  // 系数
    int e;  // 指数
    Node* Next;
};
typedef Node* List;
List Read()
{
    int n = read();
    List L = (List)malloc(sizeof(Node));
    List P = L;

    for(int i = 0;i < n;i ++)
    {
        List p = (List)malloc(sizeof(Node));
        p->c = read();
        p->e = read();
        P->Next = p;
        P = P->Next;
    }
    return L;
}
void print(List L)
{
    if(L->Next == NULL)
    {
        printf("0 0\n");
        return;
    }
    L = L->Next;
    while(L)
    {
        if(L->c == 0)
        {
            ;
        }
        else
        {
            printf("%d %d",L->c,L->e);
        }

        if(L->Next != NULL && L->Next->c != 0)
        {
            printf(" ");
        }
        L = L->Next;
    }
    printf("\n");
}
List multiply(List L1,List L2)
{
    List a = L1->Next, b = L2->Next;
    List L = (List)malloc(sizeof(Node));

    while(a)
    {
        List t = b;
        while(t)
        {
            int c = a->c * t->c;
            int e = a->e + t->e;
            List num = (List)malloc(sizeof(Node));
            num->c = c;
            num->e = e;

            List P = L;
            while(P->Next && P->Next->e > e)
            {
                P = P->Next;
            }

            if(P->Next) // 如果还有下一个 也就是要插在链中
            {
                if(P->Next->e == e)
                {
                    P->Next->c += c;
                }
                else
                {
                    num->Next = P->Next;
                    P->Next = num;
                }   
            }
            else // 如果都比链小 要插在最后
            {
                P->Next = num;
                P = num;
            }
            t = t->Next;
        }
        a = a->Next;
    }

    return L;
}
List add(List L1,List L2)
{
    List a = L1->Next , b = L2->Next;
    List L = (List)malloc(sizeof(Node));
    List P = L;

    while(a && b)
    {
        if(a->e == b->e)
        {
            if(a->c + b->c == 0)
            {
                ;
            }
            else
            {
                List p = (List)malloc(sizeof(Node));
                p->c = a->c + b->c;
                p->e = a->e;
                P->Next = p;
                P = p;
            }
            a = a->Next;
            b = b->Next;
        }
        else if(a->e > b->e)
        {
            P->Next = a;
            P = a;
            a = a->Next;
        }
        else
        {
            P->Next = b;
            P = b;
            b = b->Next;
        }
    }

    while(a)
    {
        P->Next = a;
        P = a;
        a = a->Next;
    }
    while(b)
    {
        P->Next = b;
        P = b;
        b = b->Next;
    }

    P->Next = NULL;

    return L;
}
int main()
{
    List L1 = Read(), L2 = Read();
    List r1,r2;

    r1 = multiply(L1,L2);
    print(r1);
    r2 = add(L1,L2);
    print(r2);
    
    return 0;
}
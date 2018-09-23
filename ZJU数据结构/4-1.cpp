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
struct tree
{
    int data;
    tree* left;
    tree* right;
};
typedef tree* List;
List insert(List L,int data)
{
    if(!L)
    {
        L = (List)malloc(sizeof(tree));
        L->data = data;
        L->right = NULL;
        L->left = NULL;
    }
    else if(L->data > data)
    {
        L->left = insert(L->left,data);
    }
    else if(L->data < data)
    {
        L->right = insert(L->right,data);
    }
    return L;
}
List createTree(int n)
{
    List L = NULL; // 需要初始化成NULL 否则错误

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        /*
            一开始犯了个大错误 写成直接传入指针L并且函数不返回赋值
            事实上传递指针进函数中, 函数中改变的只会是所指向的值 而非地址
            也就是一开始想着只需要一直传上面定义的L指针就可以不断的添加节点
            到指针L的想法是错的
            指针的使用还需多注意
        */
        L = insert(L,t);
    }
    return L;
}
int same(List L,List P)
{
    if(!L && !P)
    {
        return 1;
    }
    if(!L && P || L && !P)
    {
        return 0;
    }
    if(L->data != P->data)
    {
        return 0;
    }
    return same(L->left,P->left) && same(L->right,P->right);
}
int main()
{
    int n,m;

    while(scanf("%d %d",&n,&m) && n != 0)
    {
        List L = createTree(n);

        for(int i = 0;i < m;i ++)
        {
            List P = createTree(n);
            if(same(L,P))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}
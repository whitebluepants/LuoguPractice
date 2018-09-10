/* 写法一 通过并查集合并同一类的集合 */

// #include <stdio.h>
// using namespace std;
// int read()
// {
//     char ch = getchar();
//     int f = 1;
//     int x = 0;
//     while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
//     while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
//     return f?x:x*-1;
// }
// int father[100001];
// int ans[100001];
// int find(int x)
// {
//     if(father[x] == x)
//     {
//         return x;
//     }
//     else
//     {
//         return father[x] = find(father[x]);
//     }
// }
// void unio(int x,int y)
// {
//     int rootx = find(x),rooty = find(y);

//     if(rootx == rooty)
//     {
//         return ;
//     }

//     father[rooty] = rootx;

// }
// int main()
// {
//     int n = read();

//     for(int i = 0;i < n;i ++)
//     {
//         int a = read(),b = read();
        
//         for(int i = 1;i <= a;i ++)
//         {
//             father[i] = i;
//             ans[i] = 0;
//             rank1[i] = 0;
//         }

//         for(int j = 0;j < b;j ++)
//         {
//             char t[2] = {}; int x,y;
//             scanf("%s",t); x = read(),y = read();
//             if(t[0] == 'D')
//             {
//                 if(ans[x] == 0 && ans[y] == 0)
//                 {
//                     ans[x] = y;
//                     ans[y] = x;
//                 }
//                 else if(ans[x] == 0)
//                 {
//                     ans[x] = y;
//                     unio(x,ans[y]);
//                 }
//                 else if(ans[y] == 0)
//                 {
//                     ans[y] = x;
//                     unio(y,ans[x]);
//                 }
//                 else
//                 {
//                     unio(x,ans[y]);
//                     unio(y,ans[x]);
//                 }
//             }
//             else
//             {
//                 if(find(x) == find(y))
//                 {
//                     printf("In the same gang.\n");
//                 }
//                 else if(find(x) == find(ans[y]))
//                 {
//                     printf("In different gangs.\n");
//                 }
//                 else
//                 {
//                     printf("Not sure yet.\n");
//                 }
//             }
//         }
//     }   

//     return 0;
// }

/* 方法二 使用两倍的空间来维护集合 D x,y + n 代表 x和y不是一个种类 */
// #include <stdio.h>
// using namespace std;
// int read()
// {
//     char ch = getchar();
//     int f = 1;
//     int x = 0;
//     while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
//     while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
//     return f?x:x*-1;
// }
// int father[200002];
// int find(int x)
// {
//     return father[x] == x ? x : father[x] = find(father[x]);
// }
// void unio(int x,int y)
// {
//     x = find(x),y = find(y);
//     if(x == y)
//     {
//         return ;
//     }
//     father[x] = y;
// }
// int main()
// {
//     int n = read();
    
//     for(int i = 0;i < n;i ++)
//     {
//         int a = read(),b = read();
//         for(int j = 1;j <= 2 * a;j ++)
//         {
//             father[j] = j;
//         }

//         for(int j = 0;j < b;j ++)
//         {
//             char t[2] = {};
//             scanf("%s",t);
//             int x = read(),y = read();

//             if(t[0] == 'D')
//             {
//                 unio(x,y + a);
//                 unio(x + a,y);
//             }
//             else
//             {
//                 if(find(x) == find(y) || find(x + a) == find(y + a))
//                 {
//                     printf("In the same gang.\n");
//                 }
//                 else if(find(x) == find(y + a) || find(x + a) == find(y))
//                 {
//                     printf("In different gangs.\n");
//                 }
//                 else
//                 {
//                     printf("Not sure yet.\n");
//                 }
//             }
//         }
//     }

//     return 0;
// }

/* 方法三 用0和1表示当前节点和根节点是相同还是不同 最后判断是否一种就可
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
    int father;
    int rel;
};
node ans[100001];
int find(int x)
{
    if(ans[x].father == x)
    {
        return x;
    }
    else
    {
        int temp = ans[x].father;
        ans[x].father = find(ans[x].father);
        ans[x].rel = (ans[x].rel + ans[temp].rel) % 2;
        return ans[x].father;
    }
}
void unio(int x,int y)
{
    int rootx = find(x),rooty = find(y);
    if(x == y)
    {
        return ;
    }
    
    ans[rootx].father = rooty;
    ans[rootx].rel = (ans[y].rel + 1 + 2 - ans[x].rel) % 2;
}
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        int a = read(),b = read();
        
        for(int j = 1;j <= a;j ++)
        {
            ans[j].father = j;
            ans[j].rel = 0;
        }

        for(int j = 1;j <= b;j ++)
        {
            char t[2] = {};
            scanf("%s",t);
            int x = read(),y = read();

            if(t[0] == 'D')
            {
                unio(x,y);
            }
            else
            {
                if(find(x) == find(y))
                {
                    if(ans[x].rel == ans[y].rel)
                    {
                        printf("In the same gang.\n");
                    }
                    else
                    {
                        printf("In different gangs.\n");
                    }
                }
                else
                {
                    printf("Not sure yet.\n");
                }
            }
        }
    }
    return 0;
}
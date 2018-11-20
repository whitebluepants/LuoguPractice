#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <string.h>
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
int tableN,m;
int Hash[10009]; // 开10001 会炸 应该大点 应该当输入散列表长为10000时 实际应为素数10007
int num[10009];
int getNextPrime(int n)
{
    if(n == 1)
    {
        return 2;
    }
    for(int i = n;1;i ++)
    {
        int flag = 0;
        for(int j = 2;j <= sqrt(i);j ++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return i;
        }
    }
}
int HashFunc(int x,int index)
{
    int i = 1;
    int temp = index;
    while(Hash[index] != x && Hash[index] != -1)
    {
        // index = index + (i * i); // 错误写法 跟11-1一样
        index = temp + (i * i);
        i ++;
        index %= tableN;
        if(i > tableN / 2)
        {
            index = -1;
            break;
        }
    }
    return index;
}
void add(int x,int i)
{
    int A = x % tableN;

    A = HashFunc(x,A);

    if(A == -1)
    {
        num[i] = -1;
    }
    else if(Hash[A] == -1)
    {
        Hash[A] = x;
        num[i] = A;
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    
    tableN = read(),m = read();
    tableN = getNextPrime(tableN);

    memset(Hash,-1,sizeof(Hash));

    for(int i = 0;i < m;i ++)
    {
        num[i] = read();
        add(num[i],i);
    }

    int flag = 0;
    for(int i = 0;i < m;i ++)
    {
        if(flag)
        {
            printf(" ");
        }
        if(num[i] != -1)
        {
            printf("%d",num[i]);
        }
        else
        {
            printf("-");
        }
        flag = 1;
    }
    
    return 0;
}
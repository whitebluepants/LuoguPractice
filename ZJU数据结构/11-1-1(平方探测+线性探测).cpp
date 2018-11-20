// 该题一开始使用string严重超时 后来换成long long顺利AC
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
long long read()
{
    char ch = getchar();
    int f = 1;
    long long x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
// string Hash[200007];
long long Hash[200007];
int ans[200007];
int N = 200007;
int Max = 0,maxCount = 0,t;  // Max存最大次数 maxCount存最大次数的相同人数 t记录最大次数的下标
int HashFunc(long long s,int x)
{
    int i = 1,flag = 1;
    int index = x;
    while(Hash[x] != s && Hash[x] != 0) // 平方探测
    {
        // x += flag * (i * i); // 原写法
        x = index + flag * (i * i); // 正确应该是在原下标下, 加或减i平方

        if(flag == -1)
        {
            i ++; // 要在进行了加和减两次后再加加 一开始忽略了这个
        }
        flag *= -1;
        x = x % N; // 不应该除余p 而是散列表长
        x = abs(x);
    }
    // while(Hash[x] != s && Hash[x] != "") // 线性探测
    // {
    //     x ++;
    //     if(x >= N)
    //     {
    //         x = 0;
    //     }
    // }
    return x;
}
void add(long long a)
{
    // int countA = 0;

    // for(int i = 6;a[i] != '\0';i ++)
    // {
    //     // countA = countA << 4 + a[i]; 
    //     countA = countA * 10 + (a[i] - '0'); // 尽量优化过程 只对手机号码后面5位进行Hash
    // }

    int p = 200007;
    // int A = countA % p;
	int A = a % p;
	
    A = HashFunc(a,A);

    if(Hash[A] != a)
    {
        Hash[A] = a;
    }
    ans[A] ++;

    if(ans[A] == Max)
    {
        maxCount ++;
        if(Hash[A] < Hash[t])
        {
            t = A;
        }
    }
    else if(ans[A] > Max)
    {
        Max = ans[A];
        t = A;
        maxCount = 1;
    }
}
int main()
{
	// freopen("in.txt","r",stdin);
    int n = read();
    
    for(int i = 0;i < n;i ++)
    {
        long long a = read(),b = read(); // 使用数字代替string 进一步优化
        // string a,b;
        // cin >> a >> b;
        // add(a,b);  
        add(a); // 简化函数代码 提高复用
        add(b);
    }

    // for(int i = 0;i < 200007;i ++)  不用遍历 直接在线处理得出最大值
    // {
    //     if(ans[i] == Max)
    //     {
    //         maxCount ++;
    //         if(Hash[i] < Hash[t])
    //         {
    //             t = i;
    //         }
    //     }
    //     else if(ans[i] > Max)
    //     {
    //         Max = ans[i];
    //         t = i;
    //         maxCount = 1;
    //     }
    // }

    cout << Hash[t] << " " << Max;
    if(maxCount > 1)
    {
        cout << " " << maxCount;
    }

    return 0;
}
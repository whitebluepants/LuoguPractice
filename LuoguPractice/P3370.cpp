#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
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
unsigned long long Hash[10007];
int TableSize;
int ans;
unsigned long long mod=212370440130137957ll;
unsigned long long HashKey(string s)
{
	unsigned long long sum = 0;
    for(int i = 0;i < s.size();i ++)
    {
        sum = (sum * 131 + s[i]) % mod;
    }
    return sum;
}
int findKey(int key,unsigned long long s)
{
    int i = 1;
    int flag = 1;
    while(Hash[key] != 0 && Hash[key] != s)
    {
        key = key + (i * i) * flag;
        flag *= -1;
        if(flag == 1)
        {
            i ++;
        }
        key = abs(key);
        key %= TableSize;
    }
    return key;
}
void Insert(string s)
{
    unsigned long long key = HashKey(s);

    int index = findKey(key % TableSize,key);

    if(Hash[index] == key)
    {
        ;
    }
    else
    {
        ans ++;
        Hash[index] = key;
    }

    return ;
}
int getNextprime(int n)
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
int main()
{
	// freopen("in.txt","r",stdin);
    int n = read();

    TableSize = getNextprime(n);

    string t;
    for(int i = 0;i < n;i ++)
    {   
        cin >> t;
        Insert(t);
    }

    printf("%d",ans);

    return 0;
}
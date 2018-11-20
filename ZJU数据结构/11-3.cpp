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
long long Hash[100007];
string password[100007];
int tableSize = 100007;
int HashKey(long long num)
{
    return num % tableSize;
}
int Find(long long num,int index)
{
    int temp = index;
    int i = 1,flag = 1;

    while(Hash[index] != 0 && Hash[index] != num)
    {
        index = temp + flag * (i * i);
        if(flag == -1)
        {
            i ++;
        }
        flag *= -1;
        index %= tableSize;
        index = abs(index);
    }

    return index;
}
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        char op;
        cin >> op;
        long long num = read();
        string pw;
        cin >> pw;

        int index = HashKey(num);
        index = Find(num,index);

        if(op == 'L')
        {
            if(Hash[index] == 0)
            {
                cout << "ERROR: Not Exist" << endl;
            }
            else if(password[index] == pw)
            {
                cout << "Login: OK" << endl;
            }
            else
            {
                cout << "ERROR: Wrong PW" << endl;
            }
        }
        else
        {
            if(Hash[index] == 0)
            {
                Hash[index] = num;
                password[index] = pw;
                cout << "New: OK" << endl;
            }
            else
            {
                cout << "ERROR: Exist" << endl;
            }
        }
    }

    return 0;
}
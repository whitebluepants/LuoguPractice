#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
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
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void fun1(string s)
{
    int sum = 0;
    
    for(int i = 0;i < s.size();i ++)
    {
        sum = sum * 10 + s[i] - '0';
    }

    if(sum < 13)
    {
        cout << a[sum];
    }
    else
    {
        if(sum % 13 == 0)
        {
            cout << b[sum / 13];
        }
        else
        {
            cout << b[sum / 13] << " " << a[sum % 13];
        }
    }
}
void fun2(string s)
{
	int sum = 0, flag = 0;

    string t = "";
    for(int i = 0;i < s.size();i = i + 4)
    {
        t = s.substr(i,3);
        for(int j = 0;j < 13;j ++)
        {
            if(t == a[j])
            {
                sum += j;
            }
            if(t == b[j])
            {
                sum += j * 13;
            }
        }
        t = "";
    }
	printf("%d", sum);
}
int main()
{
    int n = read();
    
    for(int i = 0;i < n;i ++)
    {
        string s;
        getline(cin,s);

        if(s[0] >= '0' && s[0] <= '9')
        {
            fun1(s);
        }
        else
        {
            fun2(s);
        }
        printf("\n");
    }

    return 0;
}
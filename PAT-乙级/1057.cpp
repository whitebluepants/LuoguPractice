#include <iostream>
#include <string>
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
int main()
{
    string s;

    int sum = 0;
    getline(cin,s);
    for(int i = 0;i < s.size();i ++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            sum += s[i] - 'a' + 1;
        }
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            sum += s[i] - 'A' + 1;
        }
    }

    int cnt1 = 0,cnt2=  0;
    while(sum != 0)
    {
        int temp = sum % 2;
        sum /= 2;
        if(temp == 1)
        {
            cnt2 ++;
        }
        else
        {
            cnt1 ++;
        }
    }
    printf("%d %d",cnt1,cnt2);

    return 0;
}
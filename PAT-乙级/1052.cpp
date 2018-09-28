#include <stdio.h>
#include <string>
#include <iostream>
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
string hand[20];
string eye[20];
string mouth[20];
int main()
{
    string a,b,c;

    getline(cin,a);
    getline(cin,b);
    getline(cin,c);

    int cnt1 = 1,cnt2 = 1,cnt3 = 1;
    for(int i = 0;i < a.size();i ++)
    {
        if(a[i] == '[')
        {
            i ++;
            for(;a[i] != ']';i ++)
            {
                hand[cnt1] += a[i];
            }
            cnt1 ++;
        }
    }
    for(int i = 0;i < b.size();i ++)
    {
        if(b[i] == '[')
        {
            i ++;
            for(;b[i] != ']';i ++)
            {
                eye[cnt2] += b[i];
            }
            cnt2 ++;
        }
    }
    for(int i = 0;i < c.size();i ++)
    {
        if(c[i] == '[')
        {
            i ++;
            for(;c[i] != ']';i ++)
            {
                mouth[cnt3] += c[i];
            }
            cnt3 ++;
        }
    }
    cnt1 --,cnt2 --,cnt3 --;
    int n = read();

    for(int i = 0;i < n;i ++) 
    {
        int q = read(),w = read(),e = read(),r = read(),t = read();

        if(q > cnt1 || w > cnt2 || e > cnt3 || r > cnt2 || t > cnt1)
        {
            cout << "Are you kidding me? @\\/@" << endl;
        }
        // 序号可能为0或者负数 没有考虑好
        else if(q <= 0 || w <= 0 || e <= 0 || r <= 0 || t <= 0)
        {
            cout << "Are you kidding me? @\\/@" << endl;
        }
        else
        {
            cout << hand[q] << '(' << eye[w] << mouth[e] << eye[r] << ')' << hand[t] << endl;
        }
    }

    return 0;
}
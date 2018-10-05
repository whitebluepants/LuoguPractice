#include <stdio.h>
#include <iostream>
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
struct node
{
    string s;
    int p;
};
node ans[1001];
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        string t;
        cin >> t;
        int a = read(),b = read();
        ans[a].s = t;
        ans[a].p = b;
    }

    int k = read();

    for(int i = 0;i < k;i ++)
    {
        int t = read();
        cout << ans[t].s << " " << ans[t].p << endl;
    }

    return 0;
}
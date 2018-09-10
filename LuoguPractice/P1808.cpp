#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
#include <algorithm>
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
    int n = read();
    string s;
    map<string,int> m;
    for(int i = 0;i < n;i ++)
    {
        cin >> s;
        sort(s.begin(),s.end());
        m[s] ++;
    }
    int count = 0;
    map<string,int>::iterator itr;
    for(itr = m.begin();itr != m.end();itr ++)
    {
        count ++;
    }
    printf("%d",count);
    
    return 0;
}
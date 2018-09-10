#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
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
    map <string,int> m;
    cin >> s;
    
    for(int i = 0;s[i + 1] != '\0';i ++)
    {
        string temp;
        temp = s.substr(i,2);
        m[temp] ++;
    }
    
    string t;
    map<string,int>::iterator itr;
    int max = -1;
    itr = m.begin();
    for(;itr != m.end();itr ++)
    {
        if(itr->second > max)
        {
            max = itr->second;
            t = itr->first;
        }
    }
    cout << t;

    return 0;
}
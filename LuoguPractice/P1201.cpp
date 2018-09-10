#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
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
int main()
{
    int n = read();
    vector<pair<string,int>> v;
    
    for(int i = 0;i < n;i ++)
    {
        string temp;
        cin >> temp;
        v.push_back(make_pair(temp,0));
    }

    string name;
    while(cin >> name)
    {
        int a = read(),b = read();
        if(b == 0)
        {
            continue;
        }
        for(int i = 0;i < v.size();i ++)
        {
            if(name == v[i].first)
            {
                v[i].second -= a;
                v[i].second += a % b;
            }
        }
        int f = a / b;
        
        for(int i = 0;i < b;i ++)
        {
            string s;
            cin >> s;
            for(int j = 0;j < v.size();j ++)
            {
                if(s == v[j].first)
                {
                    v[j].second += f;
                }
            }
        }
    }

    for(int i = 0;i < v.size();i ++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
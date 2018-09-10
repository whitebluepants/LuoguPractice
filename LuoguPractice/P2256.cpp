#include <stdio.h>
#include <iostream>
#include <map>
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
int father[20001];
int rank1[20001];
int find(int x)
{
    if(father[x] == x)
    {
        return x;
    }
    else
    {
        return father[x] = find(father[x]);
    }
}
void unio(int x,int y)
{
    int rootx = find(x),rooty = find(y);
    if(rootx == rooty)
    {
        return ;
    }
    
    if(rank1[rootx] > rank1[rooty])
    {
        father[rooty] = rootx;
    }
    else
    {
        father[rootx] = rooty;
        if(rank1[rootx] == rank1[rooty])
        {
            rank1[rooty] ++;
        }
    }
}
int main()
{
    int n = read(),m = read();
    map<string,int> mm;

    for(int i = 1;i <= n;i ++)
    {
        string s;
        cin >> s;
        father[i] = i;
        mm[s] = i;
    }
    
    for(int i = 0;i < m;i ++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int x = mm[s1],y = mm[s2];
        unio(x,y);
    }

    int k = read();
    for(int i = 0;i < k;i ++)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int x = mm[s1],y = mm[s2];
        if(find(x) == find(y))
        {
            cout << "Yes." << endl;
        }
        else
        {
            cout << "No." << endl;
        }
    }

    return 0;
}
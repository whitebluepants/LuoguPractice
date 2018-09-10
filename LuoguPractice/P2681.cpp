#include <stdio.h>
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
    int n = read(),m = read();
    int ans[1001] = {};

    for(int i = 1;i <= n;i ++)
    {
        ans[i] = read();
    }

    for(int i = 0;i < m;i ++)
    {
        int a = read(),b = read(),c = read();
        
        if(a == 1)
        {
            ans[b] = c;
        }
        else
        {
            map<int,int> m;
            for(int j = b;j <= c;j ++)
            {
                m[ans[j]] ++;
            }

            map<int,int>::iterator itr;

            int mincount = 9999,max = -1;
            for(itr = m.begin();itr != m.end();itr ++)
            {
                if(itr->second > max)
                {
                    max = itr->second;
                    mincount = itr->first;
                }
                else if(itr->second == max && itr->first < mincount)
                {
                    mincount = itr->first;
                }
            }
            printf("%d\n",mincount);
        }
    }
    return 0;
}
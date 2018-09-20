#include <stack>
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
    int m = read(),n = read(),k = read();

    for(int i = 0;i < k;i ++)
    {
        int num[1001] = {};
        for(int i = 0;i < n;i ++)
        {
            num[i] = read();
        }
        int flag = 0;
        stack<int> s;
        int in[1001] = {};
        for(int i = 0;i < n;i ++)
        {
            int t = num[i];
            if(in[t])
            {
                int temp = s.top();
                s.pop();
                if(temp != t)
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                for(int i = 1;i <= t;i ++)
                {
                    if(!in[i])
                    {
                        in[i] = 1;
                        s.push(i);
                    }
                }
                if(s.size() > m)
                {
                    flag = 1;
                    break;
                }
                int temp = s.top();
                s.pop();
            }
        }
        if(flag)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}
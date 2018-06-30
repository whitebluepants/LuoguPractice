#include <stdio.h>
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
struct node
{
    int i,count,p;
    bool operator < (const node a)const
    {
        if(count > a.count)
        {
            return true;
        }
        if(count < a.count)
        {
            return false;
        }
        return i < a.i;
    }
};
node ans[200000];
node win[100000];
node lose[100000];
void merge(int w,int l)
{
    int i = 0,j = 0,k = 0;
    
    while(i < w && j < l)
    {
        if(win[i].count == lose[j].count)
        {
            if(win[i].i < lose[j].i)
            {
                ans[k] = win[i ++];
            }
            else
            {
                ans[k] = lose[j ++];
            }
        }
        else if(win[i].count > lose[j].count)
        {
            ans[k] = win[i ++];
        }
        else
        {
            ans[k] = lose[j ++];
        }
        k ++;
    }

    while(i < w)
    {
        ans[k ++] = win[i ++];
    }
    while(j < l)
    {
        ans[k ++] = lose[j ++];
    }
}
int main()
{
    int n = read(),r = read(),q = read();
    int t = 2 * n;
    for(int i = 0;i < t;i ++)
    {
        ans[i].i = i + 1;
        ans[i].count = read();
    }
    for(int i = 0;i < t;i ++)
    {
        ans[i].p = read();
    }

    sort(ans,ans + t);

    for(int i = 0;i < r;i ++)
    {
        int w = 0,l = 0;
        for(int j = 0;j < t - 1;j += 2)
        {
            if(ans[j].p > ans[j + 1].p)
            {
                win[w] = ans[j];
                win[w ++].count ++;
                lose[l ++] = ans[j + 1];
            }    
            else
            {
                win[w] = ans[j + 1];
                win[w ++].count ++;
                lose[l ++] = ans[j];
            }
        }
        merge(w,l);
    }
    printf("%d",ans[q - 1].i);

    return 0;
}
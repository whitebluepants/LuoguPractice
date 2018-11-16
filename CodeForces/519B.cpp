#include <stdio.h>
#include <set>
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
    
    multiset<int> s1;

    for(int i = 0;i < n;i ++)
    {
        int t = read();
        s1.insert(t);
    }

    multiset<int> s2;
    for(int i = 1;i <= 2;i ++)
    {
        for(int j = 0;j < n - i;j ++)
        {
            int t = read();
            s2.insert(t);
        }
        multiset<int>::iterator itr;
        for(itr = s2.begin();itr != s2.end();itr ++)
        {
            s1.erase(s1.find(*itr)); // 不能直接输入值 否则会把多个相同值直接删掉 使用迭代器
        }
        printf("%d\n",*s1.begin());
        s1.clear();
        s1.swap(s2);
    }

    return 0;
}
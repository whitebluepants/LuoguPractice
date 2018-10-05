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
    int n = read();
    double e; int d;
    scanf("%lf",&e);
    d = read();
    
    int cnt1 = 0,cnt2 = 0;
    for(int i = 0;i < n;i ++)
    {
        int m = read();
        int count = 0;
        for(int j = 0;j < m;j ++)
        {
            double t;
            scanf("%lf",&t);
            if(e > t)
            {
                count ++;
            }            
        }
        if(count > m / 2)
        {   
            if(m > d)
            {
                cnt2 ++;
            }
            else
            {
                cnt1 ++;
            }
        }
    }   
    printf("%.1f%c %.1f%c",1.0*cnt1/n*100,'%',1.0*cnt2/n*100,'%');

    return 0; 
}
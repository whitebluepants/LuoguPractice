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
    int t;
    int count = 0;
    while(scanf("%1d",&t) != EOF)
    {
        count += t;
    }
    
    int temp = count;
    int p = 1;
    while(temp > 9)
    {
        temp /= 10;
        p *= 10;
    }
    
    while(p > 0)
    {
        int temp = count / p;
        count %= p;
        p /= 10;

        switch(temp)
        {
            case 0: printf("ling"); break;
            case 1: printf("yi"); break;
            case 2: printf("er"); break;
            case 3: printf("san"); break;
            case 4: printf("si"); break;
            case 5: printf("wu"); break;
            case 6: printf("liu"); break;
            case 7: printf("qi"); break;
            case 8: printf("ba"); break;
            case 9: printf("jiu"); 
        }
        if(p != 0)
        {
            printf(" ");
        }
    }

    return 0;
}
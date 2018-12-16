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
    double ans = 1;
    double temp;

    for(int i = 0;i < 3;i ++)
    {
        int flag = 0;double max = -1;
        for(int j = 0;j < 3;j ++)
        {
            scanf("%lf",&temp);
            if(temp > max)
            {
                max = temp;
                flag = j;
            }
        }
        ans *= max;
        switch(flag)
        {
            case 0: printf("W "); break;
            case 1: printf("T "); break;
            case 2: printf("L ");
        }
    }
    printf("%.2f",(ans * 0.65 - 1) * 2);

    return 0;
}
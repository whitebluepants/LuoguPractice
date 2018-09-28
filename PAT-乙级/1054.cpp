#include <stdio.h>
#include <string.h>
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
    char s[1001] = {};
    double sum = 0;
    int count = 0;
    int n = read();
    
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s);
        int flag = 0;
        int index = -1;
        int f = 0;
        int j = 0;
        int e = 10;
        double num = 0;
        if(s[0] == '-')
        {
            f = 1;
            j = 1;
        }
        for(;j < strlen(s);j ++)
        {
            if(!(s[j] >= '0' && s[j] <= '9' || s[j] == '.'))
            {
                flag = 1;
                break;
            }
            else
            {
                if(index == - 1 && s[j] == '.')
                {
                    index = j;
                }
                else if(s[j] == '.')
                {
                    flag = 1;
                    break;
                }
                else if(index == -1)
                {
                    num = num * 10 + s[j] - '0';
                }
                else
                {
                    num += 1.0 * (s[j] - '0') / e;
                    e *= 10;
                }
            }
        }
        if(index != -1 && j - index > 3 || num < -1000 || num > 1000)
        {
            flag = 1;
        }

        if(flag)
        {
            printf("ERROR: %s is not a legal number\n",s);
        }
        else
        {
            if(f)
            {
                num *= -1;
            }
            sum += num;
            count ++;
        }
    }

    if(count == 0)
    {
        printf("The average of 0 numbers is Undefined\n");
    }
    else if(count == 1)
    {
        printf("The average of 1 number is %.2f\n",sum);
    }
    else
    {
        printf("The average of %d numbers is %.2f",count,sum / count);
    }

    return 0;
}
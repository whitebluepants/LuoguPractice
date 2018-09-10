#include <stdio.h>
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
    
    int a,b,flag;
    char ch;
    for(int i = 0;i < n;i ++)
    {
        cin >> ch;
        if(ch >= 'a' && ch <= 'c')
        {
            a = read(),b = read();
            switch(ch)
            {
                case 'a': flag = 1; break;
                case 'b': flag = 2; break;
                case 'c': flag = 3;
            }
        }
        else
        {
            a = 0;
            while(ch >= '0' && ch <= '9'){a = a * 10 + ch - '0';ch = getchar();}
            b = read();
        }
        int sum;
        char c;
        switch(flag)
        {
            case 1: c = '+'; sum = a + b; break;
            case 2: c = '-'; sum = a - b; break;
            case 3: c = '*'; sum = a * b;
        }
        int len1 = 0,len2 = 0,len3 = 0;
        printf("%d%c%d=%d\n",a,c,b,sum);
        if(a < 0)
        {
            len1 ++;
            a *= -1;
        }
        if(b < 0)
        {
            len2 ++;
            b *= -1;
            if(c == '+' || c == '-')
            {
                len2 --;
            }
        }
        if(sum < 0)
        {
            len3 ++;
            sum *= -1;
        }
        if(a == 0)
        {
            len1 ++;
        }
        if(b == 0)
        {
            len2 ++;
        }
        if(sum == 0)
        {
            len3 ++;
        }
        
        while(a > 0)
        {
            a /= 10;
            len1 ++;
        }
        while(b > 0)
        {
            b /= 10;
            len2 ++;
        }
        while(sum > 0)
        {
            sum /= 10;
            len3 ++;
        }
        printf("%d\n",2 + len1 + len2 + len3);
    }

    return 0;
}
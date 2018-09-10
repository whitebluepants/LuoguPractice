#include <stdio.h>
#include <stdbool.h>
int read()
{
    char c = getchar();
    bool f = false;
    int x = 0;
    
    while(c < '0' || c > '9') // 首先不断读入直接读入第一个数字. 碰到负号标记一下
    {
        if(c == -1) // EOF 结束
        {
            return -1;
        }
        if(c == '-')
        {
            f = true;
        }
        c = getchar();
    }
    while(c >= '0' && c <= '9') // 把之前读入的数字转化为整形 若多位数则继续读取
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return f?x:x*-1;    // 错误 写成 x*f 若f为false 就会等于0
}
int main()
{
    int a[1000] = {};
    int i = 0;
    long long sum = 0;
    while( (a[i++] = read()) != EOF);

    while(i > 0)
    {
        printf("%d\n",a[--i]);
    }
    return 0;
}

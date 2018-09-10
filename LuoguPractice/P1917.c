#include <stdio.h>
int main()
{
    char p[3][3];
    int count = 0;
    for(int i = 0;i < 3;i ++)
    {
        for(int j = 0;j < 3;j ++)
        {
            p[i][j] = getchar();
            if(p[i][j] != '-')
            {
                count ++;
            }
        }
        getchar();
        getchar(); // Linux 系统换行符为\n Windows换行符为\r\n 多出了一个字符
    }

    if( (p[0][1] != '-' && p[2][1] != '-') || (p[1][0] != '-' && p[1][2] != '-'))
    {
        printf("Dont know.\n%d",count);
        return 0;
    }

    if(p[0][1] == 'X' || p[1][0] == 'X' || p[1][2] == 'X' || p[2][1] == 'X')
    {
        printf("xiaoa will win.\n%d",count);
    }
    else
    {
        printf("Dont know.\n%d",count);
    }

    return 0;
}
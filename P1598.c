// 算法 统计好字母个数后 循环最上面数量最高的开始输出 输出一个就减 减下来 相同就一起输出
#include <stdio.h>
int main()
{
    char s[4][100];
    char p[288][26];
    int i,j,k,max = -1,t;
    for(i = 0;i < 4;i ++)
    {
        gets(s[i]);
    }    
    int word[26] = {0,};
    for(i = 0;i < 4;i ++)
    {
        for(j = 0;s[i][j] != '\0';j ++)
        {
            if(s[i][j] >= 65 && s[i][j] <= 90)
            {
                k = s[i][j] - 'A';
                word[k] ++;    
            }
        }
    }
    // 找出最大的字母的个数和位置
    for(i = 0;i < 26;i ++)
    {
        if(word[i] > max)
        {
            max = word[i];
            t = i;
        } 
    }

    int temp = max;
    // 绘制二维数组 如果等于最大的数 就放* 少于放空格
    for(i = 0;i < temp;i ++)
    {
        for(j = 0;j < 26;j ++)
        {
            if(word[j] == max)
            {
                p[i][j] = '*';
                word[j] --;
            }
            else
            {
                p[i][j] = ' ';
            }
        }
        max --;
    }
    for(j = 0;j < 26;j ++)
    {
        p[i][j] = 'A' + j;
    }

     for(i = 0;i < temp + 1;i ++)
     {
         for(j = 0;j < 26;j ++)
         {
             printf("%c ",p[i][j]);
         }
         printf("\n");
     }

    return 0;
}

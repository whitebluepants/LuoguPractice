#include <stdio.h>
int main()
{
    char word[11];
    char p[1000001];
    int flag, count = 0,t,f = 0;
    gets(word);
    gets(p);

    for(int i = 0;p[i] != '\0';i ++)
    {
        if(p[i] == word[0] || p[i] == word[0] + 32 || p[i] == word[0] - 32)
        {
            flag = 1;
            int j = 1,k = i + 1;
            for(;word[j] != '\0';j ++)
            {
                if(p[k] != word[j] && p[k] != word[j] + 32 && p[k] != word[j] - 32)
                {
                    flag = 0;
                    break;
                }
                k ++;
            }
            if(flag == 1 && i == 0 && (p[k] == ' ' || p[k] == '\0'))
            {
                count ++;
            } 
            else if(flag == 1 && p[i - 1] == ' ' && (p[k] == ' ' || p[k] == '\0'))
            {
                count ++;
            }
            if(count == 1 && f == 0)
            {
            	f = 1;
                t = i;
            }
        }
    }
    if(count == 0)
    {
        printf("%d",-1);
    }
    else
    {
        printf("%d %d",count,t);
    }    
}

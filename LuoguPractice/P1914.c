#include <stdio.h>
int main()
{
    int n,s,minus,t;
    char pw[101];
    scanf("%d",&n);
    scanf("%s",pw);
    // 97 - 122
    s = n % 26;
    for(int i = 0;pw[i] != '\0';i ++)
    {
        t = pw[i] + s;
        if(t > 122)
        {
            minus = t - 122;
            pw[i] = 97 + minus - 1;
        }
        else
        {
            pw[i] = t;
        }
    }
    printf("%s",pw);
    return 0;
}

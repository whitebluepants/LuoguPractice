#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
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
    char s[27][10] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"};
    int num[27] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,1,2,1,1,2,3};
    int ans[27] = {};
    
    for(int i = 0;i < 6;i ++)
    {
        char t[10] = {};
        scanf("%s",t);
        
        for(int j = 0;j < 27;j ++)
        {
            if(strcmp(t,s[j]) == 0)
            {
                ans[i] = num[j] * num[j] % 100;
            }
        }
    }
    
    sort(ans,ans + 6);
    int flag = 0;
    
    for(int i = 0;i < 6;i ++)
    {
        if(ans[i] == 0 && flag == 0)
        {
            continue;
        }
        if(ans[i] < 10 && flag != 0)
        {
            printf("%02d",ans[i]);
        }
        else
        {
            printf("%d",ans[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("0");
    }

    return 0;
}
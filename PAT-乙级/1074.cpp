#include <stdio.h>
#include <string.h>
using namespace std;
int read()
{
	char ch = getchar();
	int f = 1;
	int x = 0;
	while (ch < '0' || ch > '9') { if (ch == '-')f = 0; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return f ? x : x * -1;
}
/*
    一开始以为进位只有1
    其实并不是 如果进制为2 但这一位的数相加 例如为5的话 那就会进位2了
    应用除和求余计算进位和余数
*/
int main()
{
    char s[25] = {};
    char s1[25] = {};
    char s2[25] = {};
    char ans[30] = {};
    scanf("%s %s %s",s,s1,s2);
    
    int len1 = strlen(s),len2 = strlen(s1),len3 = strlen(s2);

    int l = 0,flag = 0;
    for(int i = len1 - 1,j = len2 - 1,k = len3 - 1;j >= 0 || k >= 0;j --,k --)
    {
        int jin;
        char t = s[i --];
        if(t == 'd' || t == '0')
        {
            jin = 10;
        }
        else
        {
            jin = t - '0';
        }
        
        if(j >= 0 && k >= 0)
        {
            int temp = s1[j] - '0' + s2[k] - '0';
            if(flag)
            {
                temp += flag;
                flag = 0;
            }
            if(temp >= jin)
            {
                flag = temp / jin;
                temp %= jin;
            }
            ans[l ++] = temp + '0';
        }
        else if(j >= 0)
        {
            int temp = s1[j] - '0';
            if(flag)
            {
                temp += flag;
                flag = 0;
            }
            if(temp >= jin)
            {
                flag = temp / jin;
                temp %= jin;
            }
            ans[l ++] = temp + '0';
        }
        else if(k >= 0)
        {
            int temp = s2[k] - '0';
            if(flag)
            {
                temp += flag;
                flag = 0;
            }
            if(temp >= jin)
            {
                flag = temp / jin;
                temp %= jin;
            }
            ans[l ++] = temp + '0';
        }
    }
    if(flag) 
    {
        ans[l ++] = flag + '0'; // 注
    }
    
    int f = 0;
    for(int i = l - 1;i >= 0;i --)
    {
        if(f == 0 && ans[i] == '0')
        {
            continue;
        }
        printf("%c",ans[i]);
        f = 1;
    }
    
    if(f == 0)
    {
        printf("0");
    }
    
    return 0;
}
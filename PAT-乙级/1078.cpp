#include <stdio.h>
#include <string>
#include <iostream>
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
int main()
{
    char c;
    // scanf("%c\n",&c); 会出现一个格式错误 + 答案错误
    cin >> c;
    getchar();
    string s;
    getline(cin,s);
    if(c == 'C')
    {
        for(int i = 0;i < s.length();)
        {
            int count = 0;
            char t = s[i];
            while(s[i] == t)
            {
                i ++;
                count ++;
            }
            if(count != 1)
            {
                printf("%d",count);
            }
            printf("%c",t);
        }
    }
    else
    {
        for(int i = 0;i < s.length();i ++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int temp = 0;
                while(s[i] >= '0' && s[i] <= '9')
                {
                    temp = temp * 10 + s[i] - '0';
                    i ++;
                }
                for(int j = 0;j < temp;j ++)
                {
                    printf("%c",s[i]);
                }
                if(temp == 0)
                {
                    printf("%c",s[i]);
                }
            }
            else
            {
                printf("%c",s[i]);
            }
        }
    }
    printf("\n");
    
    return 0;
}
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
    注意当B比A短的时候 B前面需要补0 继续操作下去
*/
int main()
{
	char s1[105] = {}, s2[105] = {};
	char s3[105] = {};
	scanf("%s %s", s1, s2);

	int len1 = strlen(s1), len2 = strlen(s2);

	int flag = 1,k = len1 > len2?len1 - 1:len2 - 1;
	for (int i = len2 - 1,j = len1 - 1;i >= 0 || j >= 0;i--, j--)
	{
		if (flag)
		{
			if (j >= 0)
			{
                char t;
                if(i < 0)
                {
                    t =  '0';
                }
                else
                {
                    t = s2[i];
                }
				int temp = (t - '0' + s1[j] - '0') % 13;
				if (temp < 10)
				{
					s3[k] = temp + '0';
				}
				else
				{
					switch (temp)
					{
                        case 10: s3[k] = 'J'; break;
                        case 11: s3[k] = 'Q'; break;
                        case 12: s3[k] = 'K';
					}
				}
			}
			else
			{
				s3[k] = s2[i];
			}
		}
		else
		{
			if (j >= 0)
			{
                char t;
                if(i < 0)
                {
                    t = '0';
                }
                else
                {
                    t = s2[i];
                }
				int temp = (t - '0') - (s1[j] - '0');
				if (temp < 0)
				{
					temp += 10;
				}
				s3[k] = temp + '0';
			}
			else
			{
				s3[k] = s2[i];
			}
		}
		flag ^= 1;
        k --;
	}
	printf("%s",s3);

	return 0;
}
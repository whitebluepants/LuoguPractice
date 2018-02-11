#include <stdio.h>
int main()
{
	char a[13];
	char c = '0';
	int sum = 0;
	for(int i = 0;i < 13;i ++)
	{
		scanf("%c",&a[i]);
	}
	for(int i = 0,j = 1;i < 13 - 1;i ++)
	{
		if(a[i] >= 48 && a[i] <= 57)
		{
			sum += (a[i] - '0') * j ++;
		}
	}
	int e = sum % 11;
	if( (e == a[12] - '0') || (e == 10 && a[12] == 'X') )
	{
		printf("Right");
	}
	else if(e == 10)
	{
		a[12] = 'X';
		printf("%s",a);
	}
	else
	{
		a[12] = e + '0';
		printf("%s",a);
	}
	return 0;
}

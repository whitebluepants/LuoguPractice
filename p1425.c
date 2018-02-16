#include <stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int hour = c - a;
	int min = d - b;
	if(b > d)
	{
		min = 60 + d - b;
		hour --;
	}
	printf("%d %d",hour,min);
}

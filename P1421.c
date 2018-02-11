#include <stdio.h>
int main()
{
	// a pen is 1yuan and 9 jiao
	int a,b,total;
	scanf("%d %d",&a,&b);
	total = a * 10 + b;
	printf("%d",total / 19);
}

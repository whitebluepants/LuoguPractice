#include <stdio.h>
int main()
{
   int l,r,count = 0,temp;
   scanf("%d %d",&l,&r);

   for(int i = l;i <= r;i ++)
   {
       l = i;
       while(l > 0)
       {
           temp = l % 10;
           l /= 10;
           if(temp == 2)
           {
               count ++;
           }
       }
   }
   printf("%d",count);

   return 0;
}
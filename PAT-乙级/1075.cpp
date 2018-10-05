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
struct node
{
    int next;
    int data;
};
node ans[100001];
int list[100001];
int list1[100001];
int list2[100001];
int list3[100001];
int main()
{
    int n = read(),m = read(),kk = read();

    for(int i = 0;i < m;i ++)
    {
        int a = read(),data = read(),b = read();
        ans[a].next = b;
        ans[a].data = data;
    }
    int l = 0;

    while(n != -1)
    {
        list[l ++] = n;
        n = ans[n].next;
    }

    int i = 0,j = 0,k = 0;

    for(int t = 0;t < l;t ++)
    {
        if(ans[list[t]].data < 0)
        {
            list1[i ++] = list[t];
        }
        else if(ans[list[t]].data > kk)
        {
            list3[k ++] = list[t];
        }
        else
        {
            list2[j ++] = list[t];
        }
    }

    for(int t = 0;t < i - 1;t ++)
    {
        printf("%05d %d %05d\n",list1[t],ans[list1[t]].data,list1[t + 1]);
    }
    if(i != 0)
    {
        if(j != 0)
        {
            printf("%05d %d %05d\n",list1[i - 1],ans[list1[i - 1]].data,list2[0]);
        }
        else
        {
            if(k != 0)
            {
                printf("%05d %d %05d\n",list1[i - 1],ans[list1[i - 1]].data,list3[0]);
            }
            else
            {
                printf("%05d %d -1\n",list1[i - 1],ans[list1[i - 1]].data);
            }
        }
    }

    for(int t = 0;t < j - 1;t ++)
    {
         printf("%05d %d %05d\n",list2[t],ans[list2[t]].data,list2[t + 1]);
    }
    if(j != 0)
    {
        if(k != 0)
        {
            printf("%05d %d %05d\n",list2[j - 1],ans[list2[j - 1]].data,list3[0]);
        }
        else
        {
            printf("%05d %d -1\n",list2[j - 1],ans[list2[j - 1]].data);
        }
    }
    
    for(int t = 0;t < k - 1;t ++)
    {
        printf("%05d %d %05d\n",list3[t],ans[list3[t]].data,list3[t + 1]);
    }
    if(k != 0)
    {
        printf("%05d %d -1",list3[k - 1],ans[list3[k - 1]].data);
    }

    return 0;
}
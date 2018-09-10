#include <stdio.h>
#include <algorithm>
#include <string.h>
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
    int n = read();
    char s[501] = {};
    scanf("%s",s);

    int len = strlen(s);

    sort(s,s + len);
    int count = 0;
    do
    {
        printf("%s\n",s);
        count ++;
    }while(next_permutation(s,s + len));

    printf("%d",count);

    return 0;
}
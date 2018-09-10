#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct stu
{
    char name[16];
    int grade;
};
int read()
{
    char ch = getchar();
    int f = 1;
    int x = 0;
    while(ch < '0' || ch > '9'){if(ch == '-')f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:x*-1;
}
bool cmp(stu s1,stu s2)
{
    if(s1.grade != s2.grade)
    {
        return s1.grade > s2.grade;
    }
    else
    {
        return strcmp(s1.name,s2.name) < 0;
    }
}
int main()
{
    int n = read(),g = read(),k = read();
    stu ans[10001];
    int count = 0;

    for(int i = 0;i < n;i ++)
    {
        scanf("%s",ans[i].name);
        ans[i].grade = read();
        if(ans[i].grade >= g)
        {
            count += 50;
        }
        else if(ans[i].grade >= 60)
        {
            count += 20;
        }
    }

    sort(ans,ans + n,cmp);

    printf("%d\n",count);

    int t = 1,temp = 1;
    for(int i = 0;1;i ++)
    {
        if(t > k)
        {
            break;
        }
        printf("%d %s %d\n",t,ans[i].name,ans[i].grade);
        
        if(i + 1 < n && ans[i + 1].grade == ans[i].grade)
        {
            temp ++;
        }
        else
        {
            t += temp;
            temp = 1;
        }
    }

    return 0;
}
#include <stdio.h>
#include <algorithm>
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
struct student
{
    char name[11];
    char number[11];
    int grade;
    bool operator < (const student &a) const
    {
        return grade < a.grade;
    }
};
student ans[100001];
int main()
{
    int n = read();

    for(int i = 0;i < n;i ++)
    {
        scanf("%s %s",ans[i].name,ans[i].number);
        ans[i].grade = read();
    }

    sort(ans,ans + n);

    printf("%s %s\n%s %s",ans[n - 1].name,ans[n - 1].number,ans[0].name,ans[0].number);

    return 0;
}
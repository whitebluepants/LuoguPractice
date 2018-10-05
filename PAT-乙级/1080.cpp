#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
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
    string name;
    int mid;
    int ffinal;
    int program;
    int flag1,flag2,flag3;
    int grade;
};
bool cmp(node a,node b)
{
    if(a.grade == b.grade)
    {
        return a.name < b.name;
    }
    return a.grade > b.grade;
}
node ans[50000];
map<string,int> mm;
int ccount = 0;
int main()
{
    int n = read(),m = read(),p = read();

    for(int i = 0;i < n;i ++)
    {
        string s;
        int g;
        cin >> s >> g;

        if(mm[s] != 0)
        {
            int t = mm[s];
            ans[t].name = s;
            ans[t].flag1 = 1;
            ans[t].program = g;
        }
        else
        {
            mm[s] = ++ ccount;
            ans[ccount].flag1 = 1;
            ans[ccount].program = g;
            ans[ccount].name = s;
        }
    }
    for(int i = 0;i < m;i ++)
    {
        string s;
        int g;
        cin >> s >> g;

        if(mm[s] != 0)
        {
            int t = mm[s];
            ans[t].name = s;
            ans[t].flag2 = 1;
            ans[t].mid = g;
        }
        else
        {
            mm[s] = ++ ccount;
            ans[ccount].flag2 = 1;
            ans[ccount].mid = g;
            ans[ccount].name = s;
        }
    }
    for(int i = 0;i < p;i ++)
    {
        string s;
        int g;
        cin >> s >> g;

        if(mm[s] != 0)
        {
            int t = mm[s];
            ans[t].name = s;
            ans[t].flag3 = 1;
            ans[t].ffinal = g;
        }
        else
        {
            mm[s] = ++ ccount;
            ans[ccount].name = s;
            ans[ccount].flag3 = 1;
            ans[ccount].ffinal = g;
        }
    }

    for(int i = 1;i <= ccount;i ++)
    {
        if(ans[i].program < 200)
        {
            ans[i].grade = 0;
        }
        else
        {
            if(ans[i].mid > ans[i].ffinal)
            {
                ans[i].grade = (int)((1.0 * ans[i].mid * 0.4 + 1.0 * ans[i].ffinal * 0.6) + 0.5);
            }
            else
            {
                ans[i].grade = ans[i].ffinal;
            }
        }
    }
    sort(ans + 1,ans + 1 + ccount,cmp);

    for(int i = 1;i <= ccount;i ++)
    {
        if(ans[i].grade >= 60)
        {
            cout << ans[i].name << " " << ans[i].program << " " << (ans[i].flag2 == 0?-1:ans[i].mid) << " " << (ans[i].flag3 == 0?-1:ans[i].ffinal) << " " << (int)(ans[i].grade + 0.5) << endl;
        }
    }

    return 0;
}
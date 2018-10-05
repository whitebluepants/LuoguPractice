#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
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
    int b;
    int a;
    int t;
    int count;
    int grade;
};
bool cmp(node a,node b)
{
    if(a.grade == b.grade)
    {
        if(a.count == b.count)
        {
            return a.name < b.name;
        }
        return a.count < b.count;
    }
    return a.grade > b.grade;
}
map<string,int> m;
node ans[100005];
int ccount;
int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        string a,sc;
        int g;
        cin >> a >> g >> sc;

        for(int j = 0;j < sc.size();j ++)
        {
            if(sc[j] >= 'A' && sc[j] <= 'Z')
            {
                sc[j] += ('a' - 'A');
            }
        }

        if(m[sc] == 0)
        {
            m[sc] = ++ ccount;
            ans[ccount].name = sc;
            if(a[0] == 'A')
            {
                ans[ccount].a += g;
            }
            if(a[0] == 'B')
            {
                ans[ccount].b += g;
            }
            if(a[0] == 'T')
            {
                ans[ccount].t += g;
            }
            ans[ccount].count ++;
        }
        else
        {
            int temp = m[sc];
            if(a[0] == 'A')
            {
                ans[temp].a += g;
            }
            if(a[0] == 'B')
            {
                ans[temp].b += g;
            }
            if(a[0] == 'T')
            {
                ans[temp].t += g;
            }
            ans[temp].count ++;
        }
    }

    for(int j = 1;j <= ccount;j ++)
    {
        ans[j].grade = (int)((ans[j].b * 1.0 / 1.5) + (ans[j].a) + (ans[j].t * 1.0 * 1.5));
    }
    
    sort(ans + 1,ans + 1 + ccount,cmp);

    printf("%d\n",ccount);

    int flag = 1,t = 1;
    for(int i = 1;i <= ccount;i ++)
    {
        cout << flag << " " << ans[i].name << " " << ans[i].grade << " " << ans[i].count << endl;
        if(ans[i + 1].grade == ans[i].grade)
        {
            t ++;
        }
        else
        {
            flag += t;
            t = 1;
        }
    }

    return 0;
}
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
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
	int num;
	int grade;
	string s;
	int wrong;
	int aclen;
};
bool cmp(node a, node b)
{
	if (a.wrong == b.wrong)
	{
		return a.num < b.num;
	}
	return a.wrong > b.wrong;
}
node ans[101];
int g[1001];
int main()
{
	int n = read(), m = read();

	for (int i = 0; i < m; i++)
	{
		int a = read(), b = read(), c = read();
		ans[i].grade = a;
		ans[i].aclen = c;
		ans[i].num = i + 1;
		for (int j = 0; j < c; j++)
		{
			char t;
			cin >> t;
			ans[i].s += t;
		}
	}
	string s;
	getline(cin, s);
	for (int i = 0; i < n; i++)
	{
		string t;
		getline(cin, t);
		int flag = -1;
		for (int j = 0; j < t.size(); j++)
		{
			string a;
			if (t[j] == '(')
			{
				flag++;
				j++;
				int len = t[j] - '0';
				if (len != ans[flag].aclen)
				{
					ans[flag].wrong++;
					continue;
				}
				for (; t[j] != ')'; j++)
				{
					if (t[j] >= 'a' && t[j] <= 'z')
					{
						a += t[j];
					}
				}
				sort(a.begin(), a.end());
				if (a == ans[flag].s)
				{
					g[i] += ans[flag].grade;
				}
				else
				{
					ans[flag].wrong++;
				}
			}
		}
	}
    
	for(int i = 0;i < n;i ++)
	{
	    printf("%d\n",g[i]);
	}
	sort(ans,ans + m,cmp);

	int temp = ans[0].wrong;
	if(temp == 0)
	{
	    printf("Too simple\n");
	}
	else
	{
	    printf("%d %d",ans[0].wrong,ans[0].num);
    	for(int i = 1;ans[i].wrong == temp;i ++)
    	{
    	    printf(" %d",ans[i].num);
    	}
	}

	return 0;
}
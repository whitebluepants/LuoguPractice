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
/*
    这题有点恶心=.=
    做到最后提交了只过了前3个点 才发现在读题上出了些问题
    题目是让输出 "输出错的最多的题目选项的信息" 注意是题目选项
    一开始认为是跟1058一样 是输出题目学校做错次数最多来着
    搞的我还去根据falsecount排序了...
    逻辑题难在审题上
*/
struct node
{
    int grade;
    int len;
    string s;
    int num;
    int falsecount;
};
int letterans[101][26];
node ans[101];
double grade[1001];
bool cmp1(node a,node b)
{
    if(a.falsecount == b.falsecount)
    {
        return a.num < b.num;
    }
    return a.falsecount > b.falsecount;
}
int main()
{
    int n = read(),m = read();

    for(int i = 0;i < m;i ++)
    {
        ans[i].num = i + 1;
        ans[i].grade = read();
        ans[i].len = read();
        int t = read();
        char ch;
        for(int j = 0;j < t;j ++)
        {
            scanf(" %c",&ch);
            ans[i].s += ch;
        }
    }
    string s;
	getline(cin, s);
    
    int maxx = -1; // 记录错误选项出现的最大次数
    int f = 0;
    for(int i = 0;i < n;i ++)
    {
        string t;
        getline(cin,t);
        int count = -1;
        for(int j = 0;j < t.size();j ++)
        {
            if(t[j] == '(')
            {
                count ++;
                int flag = 0;
                j ++;
                string a;

                for(;t[j] != ')';j ++)
                {
                    if(t[j] >= 'a' && t[j] <= 'z')
                    {
                        a += t[j];
                    }
                }

                sort(a.begin(),a.end());
                int len1 = ans[count].s.size();
                int len2 = a.size();

                if(a != ans[count].s)
                {
                    f = 1;
                    flag = 1;
                }

                for(int k = 0;k < len1;k ++)
                {
                    if(a.find(ans[count].s[k]) == string::npos)
                    {
                        letterans[count][ans[count].s[k] - 'a'] ++;
                        // ans[count].choose[ans[count].s[k] - 'a'].count ++;
                        // ans[count].choose[ans[count].s[k] - 'a'].ch = ans[count].s[k];
                        if(letterans[count][ans[count].s[k] - 'a'] > maxx)
                        {
                            maxx = letterans[count][ans[count].s[k] - 'a'];
                        }
                    }
                }

                for(int k = 0;k < len2;k ++)
                {
                    if(ans[count].s.find(a[k]) == string::npos)
                    {
                        letterans[count][a[k] - 'a'] ++;
                        // ans[count].choose[a[k] - 'a'].count ++;
                        // ans[count].choose[a[k] - 'a'].ch = a[k];
                        if(letterans[count][a[k] - 'a'] > maxx)
                        {
                            maxx = letterans[count][a[k] - 'a'];
                        }
                        flag = 2;
                    }
                }

                if(flag == 0)
                {
                    grade[i] += ans[count].grade;
                }
                else if(flag == 1)
                {
                    grade[i] += 1.0 * ans[count].grade / 2;
                }
                else
                {
                    ans[count].falsecount ++;
                }
            }
        }
    }

    for(int i = 0;i < n;i ++)
    {
        printf("%.1f\n",grade[i]);
    }

    if(f == 0)
    {
        printf("Too simple\n");
    }
    else
    {
        // sort(ans,ans + m,cmp1);
        // int t = ans[0].falsecount;
        // for(int i = 0;ans[i].falsecount == t;i ++)
        // {
        //     sort(ans[i].choose,ans[i].choose + 26,cmp2);
        //     int temp = ans[i].choose[0].count;
            
        //     for(int j = 0;ans[i].choose[j].count == temp;j ++)
        //     {
        //         printf("%d %d-%c\n",ans[i].falsecount,ans[i].num,ans[i].choose[j].ch);
        //     }
        // }
        for(int i = 0;i < m;i ++)
        {
            for(int j = 0;j < 5;j ++)
            {
                if(letterans[i][j] == maxx)
                {
                    printf("%d %d-%c\n",letterans[i][j],i + 1,j + 'a');
                }
            }
        }
    }

    return 0;
}
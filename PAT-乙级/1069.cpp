#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
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
map<string,int> mm;
string s[1005];
int main()
{
    int n = read(),m = read(),ss = read();

    for(int i = 1;i <= n;i ++)
    {
        cin >> s[i];
    }

    int flag = 0;
    int count = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(flag)
        {
            count ++;
            if(count == m)
            {
                while(mm[s[i]] == 1 && i <= n)
                {
                    i ++;
                }
                cout << s[i] << endl;
                mm[s[i]] ++;
                count = 0;
            }
        }
        if(i == ss)
        {
            flag = 1;
            mm[s[i]] ++;
            cout << s[i] << endl;
        }
    }
    if(flag == 0)
    {
        printf("Keep going...");
    }

    return 0;
}
#include <string>
#include <iostream>
#include <stdio.h>
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
string s;
int main()
{
    int k;
    cin >> s >> k;
    
    for(int i = 0;i < k - 1;i ++)
    {
        string t = "";
        for(int j = 0;j < s.size();)
        {
            char temp = s[j];
            int count = 0;
            while(temp == s[j])
            {
                j ++;
                count ++;
            }
            t += temp;
            t += (char)(count + '0');
        }
        cout << s << " " << t << endl;
        s = t;
    }
    cout << s << endl;

    return 0;
}
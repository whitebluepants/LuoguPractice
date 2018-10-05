#include <stdio.h>
#include <string>
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
int main()
{
    int n = read();
    getchar();
    for(int i = 0;i < n;i ++)
    {
        string t;
        getline(cin,t);
        int f1 = 0,f2 = 0,f3 = 0,count = 0;
        for(int j = 0;j < t.size();j ++)
        {
            if(t[j] >= '0' && t[j] <= '9')
            {
                f1 = 1;
                count ++;
            }
            else if(t[j] >= 'a' && t[j] <= 'z' || t[j] >= 'A' && t[j] <= 'Z')
            {
                f2 = 1;
                count ++;
            }
            else if(t[j] != '.' && t[j] != 13)
            {
                count ++;
                f3 = 1;
            }
            if(t[j] == '.')
            {
                count ++;
            }
        }
        if(count < 6)
        {
            printf("Your password is tai duan le.\n");
        }
        else
        {
            if(f3)
            {
                printf("Your password is tai luan le.\n");
            }
            else if(f1 && !f2)
            {
                printf("Your password needs zi mu.\n");
            }
            else if(!f1 && f2)
            {
                printf("Your password needs shu zi.\n");
            }
            else if(f1 && f2)
            {
                printf("Your password is wan mei.\n");
            }
        }
    }

    return 0;
}
#include <stdio.h>
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
int main()
{
    string b;
    cin >> b;
    int flag = 0;
    // 坑点 题目虽然说"本题要求你找到其变出的那个回文数。"
    // 但是如果输入的是回文数的话 直接输出即可
    for(int i = 0,j = b.size() - 1;i < j;i ++,j --)
    {
        if(b[i] != b[j])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout << b << " is a palindromic number." << endl;
        return 0;
    }

    int count = 0,f = 0;
    while(count < 10)
    {
        string a = b;
        reverse(b.begin(),b.end());
        string result;

        
        string c;
        int jin = 0;
        for(int i = a.size() - 1,j = b.size() - 1;i >= 0;i --,j --)
        {
            int temp = jin + a[i] - '0' + b[j] - '0';
            if(temp >= 10)
            {
                jin = temp / 10;
                temp %= 10;
            }
            else
            {
                jin = 0;
            }
            c = char(temp + '0') + c;
        }
        if(jin)
        {
            c = char(jin + '0') + c;
        }

        cout << a << " + " << b << " = " << c << endl;
        flag = 0;
        for(int i = 0,j = c.size() - 1;i < j;i ++,j --)
        {
            if(c[i] != c[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout << c << " is a palindromic number." << endl;
            f = 1;
            break;
        }
        b = c;
        count ++;
    }

    if(f == 0)
    {
        cout << "Not found in 10 iterations." << endl;
    }

    return 0;
}
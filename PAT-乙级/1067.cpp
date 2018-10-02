#include <stdio.h>
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
int main()
{
    string s;
    cin >> s;
    int n = read();
    int count = 0;
    string t;
    while(getline(cin,t) && t != "#")
    {
        if(count < n && t == s)
        {
            cout << "Welcome in" << endl;
            break;
        }
        else
        {
            count ++;
            cout << "Wrong password: " << t << endl;

            if(count == n)
            {
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    
    return 0;
}
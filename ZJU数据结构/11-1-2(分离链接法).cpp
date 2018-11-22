#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
struct node
{
    int count;
    string s;
    node* next;
};
typedef node* List;
struct hashtable
{
    int tableSize;
    List list;
};
typedef hashtable* Hash;
int getNextPrime(int n)
{
    if(n == 1)
    {
        return 2;
    }
    
    for(int i = n;i;i ++)
    {
        int flag = 0;
        for(int j = 2;j <= sqrt(i);j ++)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            return i;
        }
    }
}
Hash createHashTable(int n)
{
    Hash H = (Hash)malloc(sizeof(struct hashtable));
    H->tableSize = getNextPrime(2 * n);
    H->list = (List)malloc(sizeof(node) * H->tableSize);

    for(int i = 0;i < H->tableSize;i ++)
    {
        H->list[i].count = 0;
        H->list[i].next = NULL;
    }
    return H;
}
List Find(Hash H,string a,int pos)
{
    List p = H->list[pos].next;
    
    while(p && p->s != a)
    {
        p = p->next;
    }

    return p;
}
string temp;
int Max = 0,MaxCount = 0;
void insert(Hash H,string a)
{
    int sum = 0;
    for(int i = 6;a[i] != '\0';i ++)
    {
        sum = sum * 10 + (a[i] - '0');
    }

    int pos = sum % H->tableSize;

    List p = Find(H,a,pos);

    if(!p)
    {
        // 因为结构体内有string类型 使用malloc能分配空间 但不会给string调用构造函数
        // 只能用c++的new
        // p = (List)malloc(sizeof(struct node));
        p = new node();
        p->s = a;
        p->next = H->list[pos].next;
        p->count = 1;
        H->list[pos].next = p;
    }
    else
    {
        p->count ++;
    }

    if(p->count > Max)
    {
        Max = p->count;
        MaxCount = 1;
        temp = p->s;
    }
    else if(p->count == Max)
    {
        MaxCount ++;
        if(temp > p->s)
        {
            temp = p->s;
        }
    }
}
int main()
{
	// freopen("in.txt","r",stdin);
    int n = read();

    Hash H = createHashTable(n);

    for(int i = 0;i < n;i ++)
    {
        string a,b;
        cin >> a >> b;
        insert(H,a);
        insert(H,b);
    }

    cout << temp << " " << Max;
    if(MaxCount > 1)
    {
        cout << " " << MaxCount;
    }

    return 0;
}
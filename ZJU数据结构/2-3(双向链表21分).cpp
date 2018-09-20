#include <stdio.h>
#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef pair<int,string> pp;
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
    string address;
    string next;
    int data;
    node* front;
    node* rear;
};
typedef node* List;
int n,k;
List reverse(List L1)
{
    List LL = new node();
    List L = LL;
	List P = L1;
    int cnt = 0;

    while(1)
    {
        List t = P;
        cnt = 0;
        for(int i = 0;i < k && t;i ++)
        {
            t = t->rear;
            cnt ++;
        }

        if(cnt == k)
        {
            P = t;
            for(int i = 0;i < k;i ++)
            {
                List temp = new node();
                temp->address = t->address;
                temp->data = t->data;
                temp->next = t->next;
                L->rear = temp;
                L = L->rear;
                t = t->front;
            }
            L->rear = NULL;
        }
        else
        {
            P = P->rear;
            while(P)
            {
                List temp = new node();
                temp->address = P->address;
                temp->data = P->data;
                temp->next = P->next;
                L->rear = temp;
                L = L->rear;
                P = P->rear;
            }
            L->rear = NULL;
            break;
        }
    }
    return LL;
}
int main()
{
    string s;
    cin >> s;
    n = read(),k = read();
    
    map<string,pp> m;

    for(int i = 0;i < n;i ++)
    {
        string a,b;
        int t;
        cin >> a >> t >> b;
        m[a] = pp(t,b);
    }

    List L = new node();
    List P = L;
    List f;
    string b = s;

    for(int i = 0;i < n;i ++)
    {
        List t = new node();
        t->address = b;
        t->data = m[b].first;
        t->next = m[b].second;
        b = m[b].second;
        
        if(i == 0)
        {
            t->front = NULL;
        }
        else
        {
            t->front = f;
        }
        f = t;
        if(i == 0)
        {
            P->rear = t;
            P = t;
        }
        else if(P->next == t->address)
        {
            P->rear = t;
            P = t;
        }
        
    }
    P->rear = NULL;

    if(k == 1)
    {
        L = L->rear;
        while(L)
        {
            cout << L->address << " " << L->data << " " << L->next << endl;
            L = L->rear;
        }
    }
    else
    {
        List L2 = reverse(L);
        L2 = L2->rear;

        List t = L2;

        while(t)
        {
            if(t->rear != NULL)
            {
                t->next = t->rear->address;
            }
            else
            {
                t->next = "-1";
                t->rear = NULL;
            }
            t = t->rear;
        }

        while(L2)
        {
            cout << L2->address << " " << L2->data << " " << L2->next << endl;
            L2 = L2->rear;
        }
    }

    return 0;
}
#include <iostream>
using namespace std;
struct Node
{
    string name;
    Node *next;
};
Node *shead = NULL;
void sJoin(string name)
{
    Node *n=new Node{name,NULL};
    if(!shead)
    {
        shead=n;
        n->next=shead;
        return;
    }
    Node *p =shead;
    while(p->next!=shead)
        p = p->next;
    p->next=n;
    n->next=shead;
}

void sLeave(string name)
{
    if (!shead)
        return;
    Node *p=shead,*prev=NULL;
    do
    {
        if (p->name==name)
        {
            if(p==shead)
            {
                Node *last=shead;
                while(last->next!=shead)
                    last=last->next;
                if (shead->next==shead)
                    shead=NULL;
                else
                {
                    shead=shead->next;
                    last->next=shead;
                }
            }
            else
            {
                prev->next=p->next;
            }
            delete p;
            return;
        }
        prev=p;
        p=p->next;
    }
    while(p!=shead);
}

void sDisplay()
{
    if (!shead)
    {
        cout<<"Empty\n";
        return;
    }
    Node *p=shead;
    do
    {
        cout<<p->name<<" ";
        p = p->next;
    }
    while
    (p!=shead);
    cout<<endl;
}

struct DNode
{
    string name;
    DNode *next,*prev;
};
DNode *dhead=NULL;
void dJoin(string name)
{
    DNode *n=new DNode{name,NULL,NULL};
    if (!dhead)
    {
        dhead=n;
        n->next=n->prev=n;
        return;
    }
    DNode *last=dhead->prev;
    n->next=dhead;
    n->prev=last;
    last->next=n;
    dhead->prev=n;
}
void dLeave(string name)
{
    if(!dhead)
        return;
    DNode *p=dhead;
    do
    {
        if (p->name==name)
        {
            if (p->next==p)
                dhead=NULL;
            else
            {
                p->prev->next=p->next;
                p->next->prev=p->prev;
                if (p==dhead)
                    dhead=p->next;
            }
            delete p;
            return;
        }
        p=p->next;
    }
    while(p!=dhead);
}
void dDisplay()
{
    if(!dhead)
    {
        cout<<"Empty\n";
        return;
    }
    DNode *p=dhead;
    do
    {
        cout<<p->name<<" ";
        p=p->next;
    }
    while(p!=dhead);
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the Number of Data:";
    cin>>n;
    while(n--)
    {
        char op;
        string name;
        cout<<"Enter the operation(J/L/D):";
        cin>>op;
        if(op=='j')
        {
            cout<<"Enter the Data to join:";
            cin>>name;
            sJoin(name);
            dJoin(name);
        }
        else if(op=='l')
        {
            cout<<"Enter the Data to Remove:";
            cin>>name;
            sLeave(name);
            dLeave(name);
        }
        else if(op=='d')
        {
            cout<<"Singly: ";
            sDisplay();
            cout<<"Doubly: ";
            dDisplay();
        }
    }
    return 0;
}

#include <iostream>
using namespace std;
class Node
{
public:
    string so;
    Node *prev;
    Node *next;

    Node(string s)
    {
        so=s;
        prev=NULL;
        next=NULL;
    }
};
class s_list
{
    Node *head;
    Node *tail;
    int count;
public:
    s_list()
    {
        head=NULL;
        tail=NULL;
        count=0;
    }
    void addFirst(string s)
    {
        Node *n=new Node(s);

        if(head==NULL)
        {
            head=tail=n;
        }
        else
        {
            n->next=head;
            head->prev=n;
            head=n;
        }
        count++;
        display();
    }
    void addLast(string s)
    {
        Node *n=new Node(s);

        if (tail==NULL)
        {
            head=tail=n;
        }
        else
        {
            n->prev=tail;
            tail->next=n;
            tail=n;
        }
        count++;
        display();
    }
    void insertAfter(string target,string s)
    {
        Node *temp=head;

        while(temp!=NULL && temp->so!=target)
        {
            temp=temp->next;
        }

        if (temp==NULL)
        {
            cout<<"Song not found"<<endl;
            return;
        }
        Node *n=new Node(s);
        n->next=temp->next;
        n->prev=temp;
        if (temp->next != NULL)
        {
            temp->next->prev=n;
        }
        else
        {
            tail=n;
        }
        temp->next=n;
        count++;
        display();
    }
    void removeFirst()
    {
        if(head==NULL)
        {
            cout << "Playlist is empty" << endl;
            return;
        }
        Node *temp=head;
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        else
        {
            tail=NULL;
        }
        delete temp;
        count--;
        display();
    }
    void display()
    {
        Node *temp=head;

        while(temp!=NULL)
        {
            cout<<temp->so<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void size()
    {
        cout<<"Songs: "<<count<<endl;
    }
};
int main()
{
    s_list p;
    p.addFirst("A");
    p.addLast("B");
    p.insertAfter("A", "C");
    p.insertAfter("B", "D");
    p.removeFirst();
    p.size();
    return 0;
}

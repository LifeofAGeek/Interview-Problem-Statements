#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
Node *head=nullptr;

void createNode(int arr[], int n) //array data to link list data
{
    int i;
    Node *t,*last;
    head=new Node;
    head->value=arr[0];
    head->next=nullptr;
    last=head;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->value=arr[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *p) // front to end
{   cout<<"Displaying LinkedList:"<<endl;
    while(p!=0)
    {
        cout<<p->value<<" ";
        p=p->next;
    }
}
void right_shift(int k)
{
    while(k>0)
    {
        static Node *q=head,*r=nullptr;
        while(q->next!=0)
    {
        r=q;
        q=q->next;
    }
        q->next=head;
        r->next=nullptr;
        head=q;
        k--;
    }
}

int main()
{
    int a[]={1,2,1,3,4,5};
    createNode(a,6);
    cout<<endl;
    right_shift(3);
    Display(head);
}

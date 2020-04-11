#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LL{
    Node *head;
    public:
        LL()
        {
            head = NULL;
        }
        void insert( int data)
        {
            Node *temp = new Node;
            temp->data = data;
            temp->next = NULL;
            if(head==NULL)
             head = temp;
            else
            {
                Node *temp2= head;
                while(temp2->next!=NULL)
                    temp2=temp2->next;
                temp2->next = temp;
            }
        }

        void display()
        {
            Node *temp =  head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
        }

        int isempty()
        {
            if(head==NULL)
                return 1;
            else
                return 0;
        }

        Node* getHead()
        {
            return head;
        }
   
};

void union_intersection(Node* head1, Node* head2)
{
    LL uni, inter;
    Node *a = head1;
    Node *b = head2;
    map <int, int> m;
    while(a)
    {
      m[a->data]++;
      a=a->next;
    }

    while(b)
    {
        if(m.count(b->data)==1)
            {inter.insert(b->data); uni.insert(b->data); m[b->data] = -1;}
        else
        {
            uni.insert(b->data);
        }
        b=b->next;
    }
    for(auto it = m.begin(); it!=m.end(); it++)
        if(it->second!=-1)
            uni.insert(it->first);

    cout<<"\n";
    uni.display();
    cout<<"\n";
    inter.display();

}



int  main()
{
    LL l1, l2;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.display();
    l2.insert(3);
    l2.insert(5);
    l2.insert(7);
    l2.insert(9);
    cout<<"\n";
    l2.display();
    cout<<"\n";
    union_intersection(l1.getHead(), l2.getHead());
    cout<<"\n";
}

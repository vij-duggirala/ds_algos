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

void sorted_intersection(Node* head1, Node* head2)
{
    LL res;
    Node *a = head1;
    Node *b = head2;

    while(a && b)
    {
        if(a->data == b->data)
           { res.insert(a->data); a=a->next; b=b->next; }
        
        else if( a->data < b->data)
            a = a->next;
        else
            b=b->next;
    }

    res.display();

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
    sorted_intersection(l1.getHead(), l2.getHead());
    cout<<"\n";
}

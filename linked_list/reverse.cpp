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

        void display( Node* head)
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

        Node* reverse( Node* head)
        {
            Node* prev, *right , *curr;
            prev= NULL;
            curr = head;
            while(curr!=NULL)
            {
                right = curr->next;
                curr->next = prev;
                prev=curr;
                curr = right;
            }
            return prev;
        }

        Node* recursiverev(Node* head)
        {
            if(head==NULL || head->next == NULL)
                return head;

            Node *rest = recursiverev(head->next);
            head->next->next = head;

            head->next = NULL;
            return rest;

        }

        Node *getHead()
        {
            return head;
        }
     
};


int  main()
{
    LL l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.display(l.getHead());
    l.display(l.recursiverev(l.getHead()));
}

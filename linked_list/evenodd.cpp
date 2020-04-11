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
        void insert( int data )
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
                cout<<temp->data<<" ";
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
        Node *gethead()
        {
            return head;
        }

        void seg()
        {
            Node *last = head;
            Node * prev = NULL;
            Node *curr = head;
    
            while(last->next)
            {
                last = last->next;
            }

            Node *temp  =head;
            Node* new_end  = last;

            while(temp!=last && temp->data%2)
            {
                new_end->next = temp;
                new_end = new_end->next;
                temp = temp->next;
                new_end->next = NULL;
            }

        if(temp->data %2==0)
        {
            head = temp;
            while(temp!=last)
            {
                if(temp->data%2==0)
                {
                    prev = temp;
                    temp=temp->next;
                }
                else
                {
                    prev->next = temp->next;
                    temp->next = NULL;
                    new_end ->next = temp;
                    new_end=new_end->next;
                    temp = prev->next;
                }
            }
        }
        else
            prev = temp;
        
        if(new_end!=last && last->data%2)
        {
            prev->next = last->next;
            new_end->next=last;
            last->next=NULL;

        }

        }

   
};

int main()
{
    LL l ;
    l.insert(1);
   // l.insert(2);
    l.insert(3);
   // l.insert(4);
    l.insert(5);
   // l.insert(6);
    l.insert(7);
    l.insert(8);
    l.insert(9);
   // l.insert(10);
    l.insert(11);
    //l.insert(12);
    //l.insert(60);
    l.display();
    l.seg();
    cout<<"\n";
    l.display();    
}
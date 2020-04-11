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

        void krotate(int k){
                Node* temp;
                k--;
                temp  = head;
                while(k-- && temp)
                {
                    temp = temp->next;
                }
                if(temp){
                Node *head2= temp->next;
                temp->next=NULL;
                if(head2)
                temp=head2;
                while(temp->next)
                    temp=temp->next;
                temp->next = head;
                head= head2;}
        }
};

int main()
{
    LL l ;
    l.insert(2);
    l.insert(4);
    l.insert(7);
    l.insert(8);
    l.insert(9);
    //l.insert(60);
    l.display();
    l.krotate(5);
    cout<<"\n";
    l.display();    
}
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

        void deleteAlt(){
        Node *temp= head;
        while(1)
        {
            if(temp && temp->next)
                {    
                    temp->next = temp->next->next;
                    temp=temp->next;
                }
                
                else
                    break;
        }
        }
};

int main()
{
    LL l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.display();
    l.deleteAlt();
    cout<<"\n";
    l.display();
}
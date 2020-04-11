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
        Node *gethead()
        {
            return head;
        }

        Node* krev(Node*head, int k){
            int count = 0;
            Node *ne, *prev, *curr;
            curr = head;
            prev=NULL;
            ne=NULL;

            while(curr && count<k)
            {
                ne = curr->next;
                curr->next= prev; 
                prev=curr;
                curr= ne;
                count++;
            }


            if(ne!=NULL)
                head->next = krev(ne  ,k );

            return prev;       
        }

        void krev(int k)
        {
                head = krev(head, k);
        }
};

int main()
{
    LL l ;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    l.insert(8);
    l.insert(9);
    //l.insert(60);
    l.display();
    l.krev(3);
    cout<<"\n";
    l.display();    
}
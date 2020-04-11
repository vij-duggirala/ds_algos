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

        int get_middle()
        {
            Node *slow , *fast;
            slow = fast = head;

            if(slow->next==NULL)
                return -1;
            
            while(fast!=NULL && fast->next!=NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow->data;


        }
    
};
int main()
{
    LL l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.insert(7);
    l.display();
    cout<<"\n"<<l.get_middle();


}
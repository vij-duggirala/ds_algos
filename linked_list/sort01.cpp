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

       void sort()
       {
           int count[3]= {0,0,0};
            Node *temp = head;
            while(temp)
            {
                count[temp->data]++;
                temp=temp->next;
            }
            int i=0;
            temp=head;

            while(temp)
            {
                if(!count[i])
                    i++;
                else
                {
                    temp->data = i;
                    count[i]--;
                    temp=temp->next;
                }
            }
       }
};

int main()
{
    LL l ;
    l.insert(1);
    l.insert(2);
    l.insert(2);
    l.insert(0);
    l.insert(0);
    l.insert(2);
    l.insert(1);
    l.insert(0);
    l.insert(1);
    l.insert(0);
    l.insert(1);
    l.insert(2);
    //l.insert(60);
    l.display();
    l.sort();
    cout<<"\n";
    l.display();    
}
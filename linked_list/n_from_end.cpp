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

        int n_from_end( int n)
        {
            Node *left, *right;
            left= right = head;

            int cnt= 0;
            while(cnt!=n)
            {
                left = left->next;
                cnt++;
            }

            while(left!=NULL)
            {
                right = right->next;
                left= left->next;
            }

            return right->data;

        }
    
};

int main()
{
    LL l;

    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.insert(50);
    l.display();
    int n;
    cin>>n;

    cout<<l.n_from_end(n);


}
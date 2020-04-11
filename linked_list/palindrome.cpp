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

      int is_palindrome()
      { 
          stack <int> s;
          Node *temp = head;
          while(temp!=NULL)
          {
              s.push(temp->data);
              temp=temp->next;
          }

          temp=head;
          while(temp!=NULL)
          {
              if(s.top() != temp->data)
                return 0;
              s.pop();
              temp=temp->next;
          }
          return 1;

      }
    
};


int main()
{
    LL l;
    l.insert(1);
    l.insert(2);
    l.insert(2);
    l.insert(2);
    l.display();
    cout<<"\n"<<l.is_palindrome();

}
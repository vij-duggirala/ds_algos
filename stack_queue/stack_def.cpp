#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node( int x)
    {
        data =x;
        next=NULL;
    }
};

class dyn_stack
{
    node* top;
    public:
        dyn_stack()
        {
            top=NULL;
        }

        void push(int x)
        {
            node *temp = new node(x);
            temp->next =top;
            top= temp;
        }

        void pop()
        {
            if(top)
                top= top->next;
        }

        int Top()
        {
            if(!top)
                return -1;
            return top->data;
        }

        bool isempty()
        {
            if(!top)
                return true;
            else
                return false;
        }

        void print()
        {
            node *temp  = top;
            while(temp)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
};


class ndyn_stack
{
    int *arr;
    int size, top;
    public:
        ndyn_stack(int n)
        {
            arr = new int[n];
            size = n;
            top=-1;
        }

        void push(int x)
        {
            if(top != size-1)
            {
                top++;
                arr[top] = x;
            }
            else
                cout<<"overflow";
        }

        void pop()
        {
            if(top!=-1)
                top--;
            else 
                cout<<"underflow";   
        }

        int Top()
        {
            if(top!=-1) 
                return arr[top];
            else
                return -1;
        }

        bool isempty()
        {
            return top==-1;
        }

        void print()
        {
            int i=top;
            while(i!=-1)
            {
                cout<<arr[i]<<" ";
                i--;
            }
        }



};


int main()
{
    dyn_stack s;
    s.push(1);
    s.push(2);
    s.push(4);
    s.pop();
    s.push(3);
    s.push(4);
    cout<<s.Top()<<endl;
    s.print();   
    cout<<"\n";

    ndyn_stack st(4);
    st.push(1);
    st.push(2);
    st.push(4);
    st.pop();
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    st.print();   
}
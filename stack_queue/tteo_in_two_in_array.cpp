#include<bits/stdc++.h>
using namespace std;

class two_stack()
{
    int top1 , top2;
    int *arr;

    public:
        two_stack(int size)
        {
            top1= -1;
            top2=size;
            arr = new int[size];
        }

        void 1push(int x)
        {
            if(top2- top1>1)
                arr[++top1] = x;
            else
                cout<<"np";
        }

        void 2push(int x)
        {
            if(top2-top1>1)
                arr[--top2] = x;
            else
                cout<<"np";
        }

        void 1pop()
        {
            if(top1!-1)  
                top1--;
        }
        void 2top()
        {
            if(top2!=size)
                top2++;
        }
};


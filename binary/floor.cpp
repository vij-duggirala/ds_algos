#include<bits/stdc++.h>
using namespace std;

int floor(int A[], int l , int r, int key)
{
        if(key< A[0])
            return -1;
        int m;
        while(r-l>1)
        {
            m=l+(r-l)/2;
            if(A[m]<=key)
                l=m;
            else
                r=m;
        }
        return A[l];
}

int main()
{
    int n ;
    cout<<"Enter size:";
    cin>>n;
    int A[n], key;
    for(int i=0;i<n;i++)
        cin>>A[i];

    sort(A, A+n);
    cout<<"Enter key:";
    cin>>key;

    cout<<"Floor: "<<floor(A, 0 , n-1, key); 
}
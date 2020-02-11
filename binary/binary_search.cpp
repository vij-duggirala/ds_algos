#include<bits/stdc++.h>
using namespace std;

int binary_search(int A[], int l , int r , int key)
{   
        int m;
        while(l<=r)
        {
            m = (l+r)/2;
            if(A[m]==key)
                return m;
            
            if(A[m]<key)
                l=m+1;
            else
                r=m-1;
        }
        return -1;
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

    cout<<"Found at "<<binary_search(A, 0 , n-1, key); 
}
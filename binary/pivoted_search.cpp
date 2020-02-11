#include<bits/stdc++.h>
using namespace std;

int pivoted_search(int A[], int l , int r, int key)
{
        int m;
        if(l>r)
            return -1;
        
        m= l+(r-l)/2;
        if(A[m]==key)
            return m;
        
        if(A[m] >=A[l])
            if(key<=A[m] && key>=A[l])
                return pivoted_search(A, l , m-1, key);
            else
                return pivoted_search(A, m+1 , r, key);
            
        else
            if(key>=A[m] && key <=A[r] )
                return pivoted_search(A, m+1, r , key);
            else
                return pivoted_search(A, l, m-1, key);
}

int main()
{
    int n ;
    cout<<"Enter size:";
    cin>>n;
    int A[n], key;
    for(int i=0;i<n;i++)
        cin>>A[i];

    
    cout<<"Enter key:";
    cin>>key;

    cout<<"Element at index: "<<pivoted_search(A, 0,n-1, key); 
}
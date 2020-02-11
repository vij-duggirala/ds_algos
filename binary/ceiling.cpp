#include<bits/stdc++.h>
using namespace std;

int ceiling(int A[], int l , int r, int key)
{
        if(key> A[r])
            return -1;
        int m;
        while(r-l>1)
        {
            m=l+(r-l)/2;
            if(A[m]>=key)
                r=m;
            else
                l=m;
        }
        return A[r];
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

    cout<<"Ceiling: "<<ceiling(A, 0 , n-1, key); 
}
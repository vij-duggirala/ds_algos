#include<bits/stdc++.h>
using namespace std;

int Left(int A[], int l , int r, int key)
{
        int m;
        while(r-l > 1)
        {
            m=l+(r-l)/2;
            if(A[m]>=key)
                r=m;
            else
                l=m;
        }
        return r; // r gives leftmost occurence
}

int Right(int A[], int l,  int r , int key)
{
        int m;
        while(r-l >1)
        {
                m=l+(r-l)/2;
                if(A[m]<=key)
                    l=m;
                else
                    r=m;
        }
        return l; // l gives rightmost occurence
}

int count(int A[], int n , int key)
{
        //weird boundary conditions!!
        int l = Left(A, -1 , n-1, key);
        int r = Right(A, 0 , n, key);

        cout<<l<<"\t"<<r<<"\n";
        if(A[l]==key && A[r]==key)
            return (r-l+1);
        else
            return 0;
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

    cout<<"Number of occurences: "<<count(A, n, key); 
}
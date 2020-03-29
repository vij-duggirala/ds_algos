#include<bits/stdc++.h>
using namespace std;

void min_unsorted_length(int A[] , int n)
{
    int i , s, e;
    s=0;e=n-1;
    int mini , maxi;
    for(s=0;s<n-1;s++)
        if(A[s]>A[s+1])
            break;
    
    if(s==n-1)
    {
        cout<<"Array is completely sorted";
        return;
    }

    for(e=n-1;e>0;e--)
        if(A[e]<A[e-1])
            break;

    mini =maxi= A[s];
    for(i=s;i<=e;i++)   
    {
        if(A[i] > maxi)
            maxi=A[i];
        if(A[i] < mini)
            mini = A[i];
    }

    for(i=0;i<s;i++)
        if(A[i] > mini)
        {    s=i; break; }

    for(i=n-1; i>=e;i--)
        if(A[i] < maxi)
        {e=i; break;}
        


    cout<<s<<"\t"<<e<<" needs to be sorted";
}









int main()
{
    int n, i;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++)
        cin>>A[i];
    
    min_unsorted_length(A, n);
}
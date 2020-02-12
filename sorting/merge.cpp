#include<bits/stdc++.h>
using namespace std;


void merge(int A[] , int l , int m , int r)
{
    int n1= m-l+1;
    int n2= r-m;
    int i , j ,k;
    int L[n1], R[n2];

    for(i=0;i<n1;i++)
        L[i] = A[l+i];
    
    for(i=0;i<n2;i++)
        R[i]= A[m+1+i];

    i=0;j=0;
    k=l;

    while(i<n1 && j<n2)
    {
            if(L[i]<=R[j])
            {    A[k]= L[i]; i++; }
            else
            {    A[k] = R[j]; j++; }
        k++;
    }

    while(i<n1)
        A[k++]= L[i++];
    while(j<n2)
        A[k++] = R[j++];
}

void merge_sort(int A[], int l , int r)
{
    int m;
    if(l<r)
    {
        m=(l+r)/2;
        merge_sort(A, l , m);
        merge_sort(A, m+1, r);
        merge(A, l , m , r);
    }
}




int main()
{
        int n , i;
        cin>>n;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        
        merge_sort(A, 0 , n-1);
        for(i=0;i<n;i++)
            cout<<A[i]<<"\t";
}
#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

int partition(int A[], int l  , int r)
{
    int pivot = A[r]; int i,j;
    i=l-1;

    for(j=l;j<r;j++)
        if(A[j]<pivot)  
        {
                i++;
                swap(A[i], A[j]);
        }
    
    swap(A[i+1], A[r]);
    return i+1;
}

void quick_sort(int A[], int l , int r)
{
    int pi;
    if(l<r)
    {
        pi = partition(A , l , r);
        quick_sort(A, l , pi-1);
        quick_sort(A, pi+1, r);
    }
}

int main()
{
        int n , i;
        cin>>n;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        
        quick_sort(A, 0 , n-1);
        for(i=0;i<n;i++)
            cout<<A[i]<<"\t";
}

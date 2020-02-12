#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}


void heapify(int A[], int n , int i)
{
    int l = 2*i+1;
    int r=  2*i+2;

    int largest = i;
    if(l<n && A[largest]<A[l])
        largest = l;
    
    if(r<n && A[largest]<A[r])
        largest = r;

    if(largest!=i)
    {
        swap(A[i], A[largest]);
        heapify(A, n , largest);
    }
}

void heap_sort(int A[], int n)
{
    int i;
    for(i=n/2-1; i>=0;i--)
        heapify(A, n, i);

    for(i=n-1; i>=0; i--)
    {
        swap(A[0], A[i]);
        heapify(A, i ,0);
    }
}

int main()
{
        int n , i;
        cin>>n;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        
        heap_sort(A, n);
        for(i=0;i<n;i++)
            cout<<A[i]<<"\t";
}
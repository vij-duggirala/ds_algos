#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}


void bubble_sort(int A[], int n)
{
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
            if(A[j]>A[j+1])
                swap(A[j], A[j+1]);
}


int main()
{
        int n , i;
        cin>>n;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        
        bubble_sort(A, n);
        for(i=0;i<n;i++)
            cout<<A[i]<<"\t";
}
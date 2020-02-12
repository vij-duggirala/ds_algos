#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void selection_sort(int A[] , int n)
{
    int i , j, min;
    for(i=0;i<n;i++)
    {
        min = i;
        for(j=i;j<n;j++)    
            if(A[min]> A[j])
                min=j;
        if(min!=i)
            swap(A[min], A[i]);
    }
}

int main()
{
        int n , i;
        cin>>n;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        
        selection_sort(A, n);
        for(i=0;i<n;i++)
            cout<<A[i]<<"\t";
}






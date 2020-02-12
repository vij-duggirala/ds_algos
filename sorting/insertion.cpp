#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int A[] , int n)
{
    int key, i, j;
    for(i=0;i<n;i++)
    {
            key=A[i];
            j=i-1;
            while(j>=0 && A[j]>key)
            {
                    A[j+1]= A[j];
                    j--;
            }
            A[j+1]=key;
    }
}

int main()
{
        int n , i;
        cin>>n;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        
        insertion_sort(A, n);
        for(i=0;i<n;i++)
            cout<<A[i]<<"\t";
}
#include<bits/stdc++.h>
using namespace std;

void count_sort(int A[], int n , int exp)
{
    int output[n];
    int count[10];
    int i;

    for(i=0;i<10;i++)
        count[i]=0;
    
    for(i=0;i<n;i++)
        count[(A[i]/exp)%10]++;

    for(i=1;i<n;i++)
        count[i]+=count[i-1];

    for(i=n-1;i>=0;i--)
    {
        output[count[(A[i]/exp)%10]-1] = A[i];
        count[(A[i]/exp)%10]--;
    }
    
    for(i=0;i<n;i++)
        A[i]= output[i];
}

void radix_sort(int A[], int n, int max)
{
    int exp;
    for(exp=1; max/exp > 0 ; exp*=10)
        count_sort(A, n , exp);
}

int main()
{
        int n , i;
        cin>>n;
        int A[n];
        for(i=0;i<n;i++)
            cin>>A[i];
        int max = 100; // max number of digits of a single element in input array
        radix_sort(A, n, 100);
        for(i=0;i<n;i++)
            cout<<A[i]<<"\t";
}
#include<bits/stdc++.h>
using namespace std;


int maxi(int a, int b)
{
    return a>b?a:b;
}

int LIS(int A[], int n )
{
    int L[n], i , j;
    L[0]= 1;
    int max = L[0];
    for(i=1;i<n;i++)
    {
        L[i]=1;
        for(j=0;j<i;j++)
            if(A[i]>A[j])
                L[i] = maxi(L[i] , L[j]+1);
        if(L[i] > max )
            max = L[i];
    }
    return max;
}



void printLIS(int A[], int n)
{
    vector <int> L[n];
    int i , j, maxim, max_ref;
    L[0].push_back(A[0]);
    maxim = L[0].size(); max_ref=0;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            if(A[i] > A[j])
                if(L[i].size() < L[j].size() +1)
                    { L[i] = L[j]; L[i].push_back(A[i]); }

        if(L[i].size() > maxim)
        {
            maxim = L[i].size();
            max_ref=i;
        }

    }



  //  cout<<"LIS: "<<maxim;
    cout<<"\nElements:\t";
    for(i=0;i<L[max_ref].size(); i++)
        cout<<L[max_ref][i]<<"\t";
}










int main()
{
    int n, i;
    cin>>n;
    int A[n];
    for(i=0;i<n;i++)
        cin>>A[i];

    cout<<LIS(A, n);
    printLIS(A , n);


}
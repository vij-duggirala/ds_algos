#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , i , j;
    cin>>n;

    int A[n] , jumps[n] , index[n];
    for(i=0;i<n;i++)
    { jumps[i] = INT_MAX;
        index[i] = 0;    cin>>A[i];}

    
    jumps[0]  = 0;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
        {
            if(A[j] + j >= i)
                if( jumps[j]+1 < jumps[i])
                {
                    jumps[i]  =jumps[j]+1;
                    index[i] = j;
                }
        }
    
    cout<<"Min number of jumps : "<<jumps[n-1]<<"\n";
    cout<<0<<"->";
    for(i=1;i<n;i++)
        if(index[i]!=index[i-1])
            cout<<index[i]<<"->";
    cout<<n-1;
    


}
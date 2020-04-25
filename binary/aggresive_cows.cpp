#include<bits/stdc++.h>
using namespace std;
#define int long long


int check( int mid , int k , vector<int> A)
{
    int prev = A[0];
    int cnt = 1;
    int i=0;
    while(cnt!=k)
    {
            while(i<A.size() && A[i] - prev < mid)
                    i++;
             
            if(i==A.size())
                return 0;
            else
                prev = A[i];
                cnt++;
    }
    
    return 1;


}

int32_t main()
{
    int t, n , k,i;
    cin>>t;
    vector<int> A;
    while(t--)
    {
        cin>>n;
        cin>>k;

        A.resize(n);
        for(i=0;i<n;i++)
            cin>>A[i];
        sort(A.begin() , A.end());
        int l =A[0];
        int r = A[n-1];
        while(r-l>1)
        {
            int mid = l+(r-l)/2;
            if( check(mid , k, A))
                l = mid;
            else
                r = mid; 
        }
        cout<<l<<"\n";

    }

}
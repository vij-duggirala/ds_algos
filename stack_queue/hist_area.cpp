#include <bits/stdc++.h>
using namespace std;

int main(){
    int t , n , i  , j;
    cin>>t;
    while(t--)
    {
        
        cin>>n;
        vector <int> A;
        A.resize(n);
        for(i=0;i<n;i++)
            cin>>A[i];
        vector<int> l , r;
        l.resize(n);r.resize(n);
        
        stack<int> s;
        while(!s.empty())
            s.pop();
        l[0] = -1;
        s.push(0);
        for(i=1;i<n;i++)
        {
            while(!s.empty() && A[i] <= A[s.top()])
                s.pop();
            if(s.empty())
                l[i] = -1;
            else
                l[i] = s.top();
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        r[n-1] = n;
        s.push(n-1);
        for(i=n-2;i>=0;i--)
        {
            while(!s.empty() && A[i] <= A[s.top()])
                s.pop();
            if(s.empty())
                r[i] = n;
            else
                r[i] =s.top();
            s.push(i);
        }
        
        int res = 0;
        for(i=0;i<n;i++)
            res = max( res , A[i]* (r[i]- l[i]-1));
        for(i=0;i<n;i++)
            cout<<l[i]<<" ";
        cout<<"\n";
        for(i=0;i<n;i++)
            cout<<r[i]<<" ";
        cout<<"\n";
        cout<<res<<endl;
    }
}
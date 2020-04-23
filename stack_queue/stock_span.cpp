#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n  , t, i , j , cnt;
    vector <int> A;
    vector <int> res;
    cin>>t;
    stack <int> s;

    while(t--)
    {
        cin>>n;
        while(!s.empty())
            s.pop();
        A.resize(n); res.resize(n);
        for(i=0;i<n;i++)
            cin>>A[i]; 
        i = 0;
        s.push(0); res[0] = 1;
        i++;
        while(i<n)
        {
            while(!s.empty() && A[s.top()] <= A[i] )
                s.pop();
            
            if(s.empty())
                res[i] = i+1;
            else
                res[i]  = i - s.top();
            
            s.push(i);
            i++;
        }

        for(i=0;i<n;i++)
            cout<<res[i]<<" ";
        cout<<endl;

    }


}
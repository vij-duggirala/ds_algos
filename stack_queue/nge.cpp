#include <bits/stdc++.h>
using namespace std;

int main() {
	int i ,  j , n , t;
	cin>>t;
	stack <int>s;
	vector <int > res;
	vector<int> A;
	while(t--)
	{
	    cin>>n;
	    A.resize(n);
	    res.resize(n);
	    for(i=0;i<n;i++)    
	        cin>>A[i];
	   s.push(0);
	   i=1;
	   while(i<n)
	   {
	       while(!s.empty() && A[i] > A[s.top()] )
                {res[s.top()] = A[i]; s.pop();}
            s.push(i);
            i++;
	   }
	   while(!s.empty())
	   {
	       res[s.top()]=-1;
	       s.pop();
	   }
	   
	   for(i=0;i<n;i++)
	    cout<<res[i]<<" ";
	   cout<<"\n";
	   
	}
	return 0;
}
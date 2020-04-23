#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, n, i , j, sum ;
	vector<int> A, left, right;
	cin>>t;
	while(t--)
	{
        sum=0;
	    cin>>n;
	    A.resize(n);
	    left.resize(n);
	    right.resize(n);
	    left.clear();right.clear(); A.clear();
	    for(i=0;i<n;i++)
	         cin>>A[i];
	    left[0] = A[0];
	    right[n-1] = A[n-1];
	    for(i=1;i<n;i++)    
	        left[i] = max(A[i] , left[i-1]);
	   
	   for(i=n-2;i>=0; i--)
	    right[i] = max( A[i] , right[i+1]);
	   
	    for(i=1;i<n-1;i++)   
	        sum += (min(left[i] , right[i]) - A[i])>0?(min(left[i] , right[i]) - A[i]):0;
	   
	   cout<<sum<<"\n";
	}
	   

}
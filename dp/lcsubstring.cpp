#include<bits/stdc++.h>
using namespace std;


int main()
{
    string a , b;
    cin>>a;
    cin>>b;
    int n , m, i ,j, res, max;
    m= a.length();
    n=b.length();
    max=0;
    int dp[m+1][n+1];
    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if( a[i-1]==b[j-1])
            {
                dp[i][j] = 1+ dp[i-1][j-1];
                if(dp[i][j]>max)
                   { max = dp[i][j]; res=i-1;}
            }
            else
                dp[i][j] = 0;
        
    string c;
 j=res;
    for(;j>=res-max+1; j--)
         c+=a[j];
    cout<<"\n"<<max;
  reverse(c.begin() ,c.end());
   cout<<"\nSubstring: "<<c; 

}
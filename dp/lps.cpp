#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int i , j ,n, k;
    n= a.length();

    int dp[n][n];

    for(i=0;i<n;i++)
        dp[i][i] = 1;
    
    for(i=0;i<n-1;i++)
        if(a[i] == a[i+1])
            dp[i][i+1]= 2;
        else
            dp[i][i+1] = 1;
        
    for(k=3; k<=n;k++)
        for(i=0;i<n;i++)
        {
            j=i+k-1;
            if(j<n){
            if(a[i] == a[j])
                dp[i][j] = 2+ dp[i+1][j-1];
            else
                dp[i][j] = max( dp[i+1][j] , dp[i][j-1]);
            }
            else
                dp[i][j] = -1;
        }
    

    
    cout<<dp[0][n-1];

    //to print , get lcs of string and it's reverse


}